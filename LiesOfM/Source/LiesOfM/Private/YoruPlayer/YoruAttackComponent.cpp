// Fill out your copyright notice in the Description page of Project Settings.


#include "YoruPlayer/YoruAttackComponent.h"
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include <InputMappingContext.h>
#include "YoruPlayer/Yoru.h"
#include "YoruPlayer/YoruMoveComponent.h"
#include "YoruPlayer/YoruStatComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Weapon/WeaponBase.h"
#include "TOMDataTable.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Enemy/EnemyBase.h"
#include "Subsystems/TOMAudioSubsystem.h"
#include "SOund/SoundCue.h"
#include "TOMGameInstance.h"
#include "LevelDesign/LevelElementBase.h"
#include "Interface/HitEffectInterface.h"
#include "Collision/CollisionChannel.h"
#include "YoruPlayer/YoruDefenceComponent.h"
#include "Kismet/GameplayStatics.h"
#include "YoruPlayer/YoruLockonComponent.h"

UYoruAttackComponent::UYoruAttackComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UInputAction> lightAttackActionFinder(TEXT("/Script/EnhancedInput.InputAction'/Game/AAA/Input/IA_lightAttack.IA_lightAttack'"));

	if (lightAttackActionFinder.Succeeded())
	{
		lightAttackAction = lightAttackActionFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UCurveFloat> curveFinder(TEXT("/Script/Engine.CurveFloat'/Game/AAA/Curves/C_AttackDirection.C_AttackDirection'"));

	if (curveFinder.Succeeded())
	{
		curve = curveFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> wallHitMontageFinder(TEXT("/Script/Engine.AnimMontage'/Game/AAA/Animations/Yoru/GreatSwordMove/AM_GreatSwordWallHit.AM_GreatSwordWallHit'"));

	if (wallHitMontageFinder.Succeeded())
	{
		wallHitMontage = wallHitMontageFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> grabAttackMontageFinder(TEXT("/Script/Engine.AnimMontage'/Game/AAA/Animations/Yoru/GreatSwordMove/AM_GreatSword_GrabAttack.AM_GreatSword_GrabAttack'"));

	if (grabAttackMontageFinder.Succeeded())
	{
		grabAttackMontage = grabAttackMontageFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<USoundBase> swordHitSoundFinder(TEXT("/Script/Engine.SoundWave'/Game/AAA/Audio/SwordHit/The_sound_of_blood_f.The_sound_of_blood_f'"));

	if (swordHitSoundFinder.Succeeded())
	{
		swordHitSound = swordHitSoundFinder.Object;
	}
}

void UYoruAttackComponent::BeginPlay()
{
	Super::BeginPlay();

	if (curve)
	{
		FOnTimelineFloat TimelineCallback;

		TimelineCallback.BindUFunction(this, FName("RotateAttackDirection"));
		attackDirectionTimeLine.AddInterpFloat(curve, TimelineCallback);
	}
}

void UYoruAttackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	attackDirectionTimeLine.TickTimeline(DeltaTime);
}

void UYoruAttackComponent::SetupPlayerInputComponent(UEnhancedInputComponent* enhancedInputComponent)
{
	enhancedInputComponent->BindAction(lightAttackAction, ETriggerEvent::Triggered, this, &UYoruAttackComponent::Attack);
}

void UYoruAttackComponent::AttackCounterHandler()
{
	attackCounter++;
	GetWorld()->GetTimerManager().SetTimer(attackTimeHandle, this, &UYoruAttackComponent::ResetAttackCounter, 1.8f, false);
}

void UYoruAttackComponent::Attack()
{
	if (me->currentRightWeaponState == EUseWeaponState::NONE) return;

	if (me->moveComp->GetIsMovementInput() && me->statComp->CheckStamina(1.0f))
	{
		GrabAttackTrace();

		if (grabActor)
		{
			GrabAttack();
		}
		else
		{
			me->statComp->CallRegenerateStopStamina();
			HandleAttack();
		}
	}
}

void UYoruAttackComponent::HandleAttack()
{
	me->moveComp->MovementInputHandler(0.0f, true);
	me->statComp->DecreaseStamina(10.0f);
	me->statComp->CallUpdateStamina();
	UpdateAttackRotation();
	me->GetMesh()->GetAnimInstance()->Montage_Play(GetCorrectAttackAnimation());
	me->statComp->HandleStaminaRegen(true, 0.75f);

}

void UYoruAttackComponent::UpdateAttackRotation()
{
	if (me->lockonComp->lockonTarget) return;


	if (me->moveComp->HasMovementKeyInput())
	{
		startYaw = me->GetActorRotation().Yaw;
		deltaYaw = charMoveComp->GetLastInputVector().ToOrientationRotator().Yaw - startYaw;
		attackDirectionTimeLine.PlayFromStart();
	}
}

UAnimMontage* UYoruAttackComponent::GetCorrectAttackAnimation()
{
	auto list = me->equippedWeapon->attackAnimations->GetRowNames();
	FWeaponData* animData = me->equippedWeapon->attackAnimations->FindRow<FWeaponData>(list[0], FString(""));
	me->currentPlayerState = EPlayerState::LightAttack;

	return CheckIfCounterExceedsAttack(animData->lightAttakMontages);


}

UAnimMontage* UYoruAttackComponent::CheckIfCounterExceedsAttack(const TArray<UAnimMontage*>& animations)
{
	if (attackCounter >= animations.Num() - 1)
	{
		ResetAttackCounter();
		return animations.Last();
	}
	else
	{
		AttackCounterHandler();
		return animations[attackCounter - 1];
	}
	return nullptr;
}

void UYoruAttackComponent::RotateAttackDirection()
{
	float currentValue = curve->GetFloatValue(attackDirectionTimeLine.GetPlaybackPosition());
	me->SetActorRotation({ 0,currentValue * deltaYaw + startYaw,0 });
}

void UYoruAttackComponent::TriggerLineTrace()
{
	hitActors.Reset();
	GetWorld()->GetTimerManager().SetTimer(lineTraceTimeHandle, this, &UYoruAttackComponent::ApplyLineTrace, 0.01, true);
}

void UYoruAttackComponent::ApplyLineTrace()
{
	FVector start{ me->equippedWeapon->weaponMesh->GetSocketLocation(TEXT("StartPoint")) };
	FVector end{ me->equippedWeapon->weaponMesh->GetSocketLocation(TEXT("EndPoint")) };
	TArray<AActor*> ignoreActors;
	TArray<FHitResult> outHits;
	ignoreActors.Add(me->equippedWeapon);
	ignoreActors.Add(me);
	bool isHit = UKismetSystemLibrary::SphereTraceMulti(GetWorld(), start, end, 15.0, ETraceTypeQuery::TraceTypeQuery3, false, ignoreActors, EDrawDebugTrace::None, outHits, true);
	if (isHit)
	{
		for (const auto& hitResult : outHits)
		{
			if (hitResult.GetActor()->GetClass()->IsChildOf<AEnemyBase>() && !hitActors.Contains(hitResult.GetActor()))
			{
				hitActors.Add(hitResult.GetActor());
				Cast<AEnemyBase>(hitResult.GetActor())->ReceiveDamage(CaculateDamage(), me, hitResult, false);
				UGameplayStatics::PlaySoundAtLocation(this, swordHitSound, hitResult.ImpactPoint, 1.0f, 1.0f, 0.1f);
			}
			else if (hitResult.GetActor()->GetClass()->ImplementsInterface(UHitEffectInterface::StaticClass()) && !hitActors.Contains(hitResult.GetActor()))
			{
				hitActors.Add(hitResult.GetActor());
				IHitEffectInterface::Execute_ReactToEffect(hitResult.GetActor(), hitResult.ImpactPoint);
				
				auto tempObject{ Cast<ALevelElementBase>(hitResult.GetActor()) };
				if (tempObject && tempObject->isBlockable)
				{
					StopLineTrace();
					me->GetMesh()->GetAnimInstance()->Montage_Play(wallHitMontage);
					me->moveComp->MovementInputHandler(1.3f, false);
				}
			}
		}
		
	}
}

void UYoruAttackComponent::StopLineTrace()
{
	GetWorld()->GetTimerManager().ClearTimer(lineTraceTimeHandle);
}

float UYoruAttackComponent::CaculateDamage()
{
	float attackDamage{};
	switch (me->currentPlayerState)
	{
		case EPlayerState::LightAttack:
			attackDamage = me->equippedWeapon->GetdefaultDamage();
			break;
		default:
			break;
	}
	return attackDamage;
}

void UYoruAttackComponent::GrabAttackTrace()
{
	FVector start{ me->GetActorLocation() };
	FVector end{ me->GetActorLocation() };
	TArray<AActor*> ignoreActors{};
	TArray<FHitResult> outHits{};

	bool isEnemy = UKismetSystemLibrary::SphereTraceMulti(GetWorld(), start, end, 120.0f, TCHANNEL_PLAYERDAMAGE, false, ignoreActors, EDrawDebugTrace::None, outHits, true);

	if (isEnemy)
	{
		for (const FHitResult& hitResult : outHits)
		{
			grabActor = Cast<AEnemyBase>(hitResult.GetActor());
			if (grabActor)
			{
				FVector hitdirection{ (hitResult.GetActor()->GetActorLocation() - me->GetActorLocation()).GetSafeNormal2D() };
				FVector direction{ hitResult.GetActor()->GetActorRotation().Vector().GetSafeNormal2D() };
				FVector rightDirection{ (FRotationMatrix(hitResult.GetActor()->GetActorRotation()).GetScaledAxis(EAxis::Y)).GetSafeNormal2D() };
				double degree{ FMath::RadiansToDegrees(FMath::Acos((FVector::DotProduct(direction, hitdirection)))) };

				if (grabActor->isElite)
				{
					if (degree >= 135.0)
					{
						if (grabActor->currentEnemyState == EEnemyState::Groggy)
						{
							grabPoint = grabActor->GetActorLocation() + direction * 150.0 - rightDirection * 20.0;
							isGrabAttackFront = true;
							return;
						}
					}
					else if (degree <= 45.0)
					{
						if (grabActor->currentEnemyState == EEnemyState::Groggy)
						{
							grabPoint = grabActor->GetActorLocation() - direction * 150.0 - rightDirection * 20.0;
							isGrabAttackFront = false;
							return;
						}
					}
				}
				else
				{
					if (degree <= 45.0)
					{
						grabPoint = grabActor->GetActorLocation() - direction * 150.0 - rightDirection * 20.0;
						isGrabAttackFront = false;
						return;
					}
				}

				grabActor = nullptr;
			}
		}
	}
}

void UYoruAttackComponent::GrabAttack()
{
	me->moveComp->MovementInputHandler(0.0f, true);
	me->defenceComp->SetInvincibilityTime(3.9f);
	grabPoint.Z = me->GetActorLocation().Z;
	me->SetActorLocation(grabPoint);
	if (me->lockonComp->lockonTarget == nullptr)
	{
		me->lockonComp->SetLockonTarget(grabActor);
	}
	me->GetMesh()->GetAnimInstance()->Montage_Play(grabAttackMontage);
	grabActor->GrabAttacked(isGrabAttackFront);
}
