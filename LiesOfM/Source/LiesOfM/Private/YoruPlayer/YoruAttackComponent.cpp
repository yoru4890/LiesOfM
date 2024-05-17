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
	GetWorld()->GetTimerManager().SetTimer(attackTimeHandle, this, &UYoruAttackComponent::ResetAttackCounter, 2.0f, false);
}

void UYoruAttackComponent::Attack()
{
	if (me->moveComp->GetIsMovementInput() && me->statComp->CheckStamina(1.0f))
	{
		me->statComp->CallRegenerateStopStamina();
		HandleAttack();
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
	bool isHit = UKismetSystemLibrary::SphereTraceMulti(GetWorld(), start, end, 15.0, ETraceTypeQuery::TraceTypeQuery3, false, ignoreActors, EDrawDebugTrace::ForDuration, outHits, true);
	if (isHit)
	{
		for (const auto& hitResult : outHits)
		{
			if (hitResult.GetActor()->GetClass()->IsChildOf<AEnemyBase>() && !hitActors.Contains(hitResult.GetActor()))
			{
				hitActors.Add(hitResult.GetActor());
				Cast<AEnemyBase>(hitResult.GetActor())->ReceiveDamage(CaculateDamage(), me);
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
