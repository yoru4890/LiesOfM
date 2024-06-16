// Fill out your copyright notice in the Description page of Project Settings.


#include "YoruPlayer/YoruDefenceComponent.h"
#include "TOMDataTable.h"
#include "YoruPlayer/Yoru.h"
#include "TOMGameInstance.h"
#include "YoruPlayer/YoruMoveComponent.h"
#include "YoruPlayer/YoruAttackComponent.h"
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include <InputMappingContext.h>
#include "Animation/ChangeParryingAnimNotify.h"
#include "YoruPlayer/YoruStatComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Subsystems/TOMAudioSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Weapon/WeaponBase.h"
#include "Interface/DamageInteractions.h"

UYoruDefenceComponent::UYoruDefenceComponent()
{
	static ConstructorHelpers::FObjectFinder<UInputAction> blockActionFinder(TEXT("/Script/EnhancedInput.InputAction'/Game/AAA/Input/IA_Blocking.IA_Blocking'"));

	if (blockActionFinder.Succeeded())
	{
		blockAction = blockActionFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> blockMontageFinder(TEXT("/Script/Engine.AnimMontage'/Game/AAA/Animations/Yoru/GreatSwordMove/AM_Blocking.AM_Blocking'"));

	if (blockMontageFinder.Succeeded())
	{
		blockMontage = blockMontageFinder.Object;
	}
}

void UYoruDefenceComponent::BeginPlay()
{
	Super::BeginPlay();
	
	InitAnimNotify();
	InitData();
	InitFX();
}

void UYoruDefenceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UYoruDefenceComponent::SetupPlayerInputComponent(UEnhancedInputComponent* enhancedInputComponent)
{
	enhancedInputComponent->BindAction(blockAction, ETriggerEvent::Started, this, &UYoruDefenceComponent::Block);
	enhancedInputComponent->BindAction(blockAction, ETriggerEvent::Canceled, this, &UYoruDefenceComponent::UnBlock);
	enhancedInputComponent->BindAction(blockAction, ETriggerEvent::Completed, this, &UYoruDefenceComponent::UnBlock);
}

void UYoruDefenceComponent::HitReaction(float damageAmount, AActor* attackingActor, const FHitResult& hitResult, bool isRedAttack)
{
	if (isHittable)
	{
		bool isHit{true};
		HandleHit();

		FPlayerData* hitReactionAnimData = me->singleGameInstance->playerDataTable->FindRow<FPlayerData>(me->GetDataTableRowNames()[0], FString(""));
		hitReactions = hitReactionAnimData->hitReactionMontages;

		FVector actorDirection{ me->GetActorRotation().Vector().GetSafeNormal2D() };
		FVector actorRightDirection{ (FRotationMatrix(me->GetActorRotation()).GetScaledAxis(EAxis::Y)).GetSafeNormal2D() };
		FVector hitDirection{ (hitResult.ImpactPoint - me->GetActorLocation()).GetSafeNormal2D() };
		double rightDotResult{ FVector::DotProduct(actorRightDirection, hitDirection) };
		double angle{ FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(actorDirection, hitDirection))) };

		IDamageInteractions* damageInterface = Cast<IDamageInteractions>(attackingActor);

		if (rightDotResult < 0)
		{
			angle *= -1;
		}

		if (angle <= 45.0f && angle >= -45.0f)
		{
			FVector parryPoint{ CaculateParryPoint(hitResult.ImpactPoint) };

			if (isParrying)
			{
				if (!Parry(damageAmount))
				{
					me->GetMesh()->GetAnimInstance()->Montage_Play(hitReactions[0]);
					UGameplayStatics::PlaySound2D(this, hurtSound[FMath::RandHelper(hurtSound.Num())]);
					UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), bloodFX, hitResult.ImpactPoint);
				}
				else
				{
					damageInterface->ReceiveGroggyDamage(50.0f, me);
					UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), parryingFX, parryPoint);
					UGameplayStatics::PlaySoundAtLocation(this, parryingSound[FMath::RandHelper(parryingSound.Num())], parryPoint, 1.0f, 1.0f, 0.1f);
					isHit = false;
					if (isRedAttack)
					{
						ParryingBackMove();
					}
				}
			}
			else if (me->GetPlayerState() == EPlayerState::Blocking)
			{
				CaculateBlock(damageAmount);
				UGameplayStatics::PlaySoundAtLocation(this, blockingSound[FMath::RandHelper(blockingSound.Num())], parryPoint, 1.0f, 1.0f, 0.1f);
				UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), blockingFX, parryPoint);

				isHit = false;
			}
			else
			{
				me->GetMesh()->GetAnimInstance()->Montage_Play(hitReactions[0]);
				UGameplayStatics::PlaySound2D(this, hurtSound[FMath::RandHelper(hurtSound.Num())]);
				UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), bloodFX, hitResult.ImpactPoint);
			}
		}
		else if (angle > 45.0f && angle <= 135.0f)
		{
			FVector parryPoint{ CaculateParryPoint(hitResult.ImpactPoint) };

			if (isParrying)
			{
				if (!Parry(damageAmount))
				{
					me->GetMesh()->GetAnimInstance()->Montage_Play(hitReactions[1]);
					UGameplayStatics::PlaySound2D(this, hurtSound[FMath::RandHelper(hurtSound.Num())]);
					UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), bloodFX, hitResult.ImpactPoint);
				}
				else
				{
					damageInterface->ReceiveGroggyDamage(50.0f, me);
					UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), parryingFX, parryPoint);
					UGameplayStatics::PlaySoundAtLocation(this, parryingSound[FMath::RandHelper(parryingSound.Num())], parryPoint, 1.0f, 1.0f, 0.1f);
					isHit = false;
					if (isRedAttack)
					{
						ParryingBackMove();
					}
				}
			}
			else if (me->GetPlayerState() == EPlayerState::Blocking)
			{
				CaculateBlock(damageAmount);
				UGameplayStatics::PlaySoundAtLocation(this, blockingSound[FMath::RandHelper(blockingSound.Num())], parryPoint, 1.0f, 1.0f, 0.1f);
				UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), blockingFX, parryPoint);

				isHit = false;
			}
			else
			{
				me->GetMesh()->GetAnimInstance()->Montage_Play(hitReactions[1]);
				UGameplayStatics::PlaySound2D(this, hurtSound[FMath::RandHelper(hurtSound.Num())]);
				UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), bloodFX, hitResult.ImpactPoint);
			}
		}
		else if (angle < -45.0f && angle >= -135.0f)
		{
			FVector parryPoint{ CaculateParryPoint(hitResult.ImpactPoint) };

			if (isParrying)
			{
				if (!Parry(damageAmount))
				{
					me->GetMesh()->GetAnimInstance()->Montage_Play(hitReactions[3]);
					UGameplayStatics::PlaySound2D(this, hurtSound[FMath::RandHelper(hurtSound.Num())]);
					UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), bloodFX, hitResult.ImpactPoint);
				}
				else
				{
					damageInterface->ReceiveGroggyDamage(50.0f, me);
					UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), parryingFX, parryPoint);
					UGameplayStatics::PlaySoundAtLocation(this, parryingSound[FMath::RandHelper(parryingSound.Num())], parryPoint, 1.0f, 1.0f, 0.1f);
					isHit = false;
					if (isRedAttack)
					{
						ParryingBackMove();
					}
				}
			}
			else if (me->GetPlayerState() == EPlayerState::Blocking)
			{
				CaculateBlock(damageAmount);
				UGameplayStatics::PlaySoundAtLocation(this, blockingSound[FMath::RandHelper(blockingSound.Num())], parryPoint, 1.0f, 1.0f, 0.1f);
				UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), blockingFX, parryPoint);

				isHit = false;
			}
			else
			{
				me->GetMesh()->GetAnimInstance()->Montage_Play(hitReactions[3]);
				UGameplayStatics::PlaySound2D(this, hurtSound[FMath::RandHelper(hurtSound.Num())]);
				UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), bloodFX, hitResult.ImpactPoint);
			}
		}
		else
		{
			me->GetMesh()->GetAnimInstance()->Montage_Play(hitReactions[2]);
			UGameplayStatics::PlaySound2D(this, hurtSound[FMath::RandHelper(hurtSound.Num())]);
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), bloodFX, hitResult.ImpactPoint);
		}

		me->statComp->DecreaseHP(damageAmount);

		if (me->currentRightWeaponState == EUseWeaponState::GREATSWORD)
		{
			me->moveComp->EquipRightWeapon();
			me->moveComp->HiddenItem();
		}

		if (isHit)
		{
			SetInvincibilityTime(0.4f);
		}
	}
}

void UYoruDefenceComponent::HandleHit()
{
	me->moveComp->MovementInputHandler(0.0f, true);
	me->attackComp->StopLineTrace();
}

void UYoruDefenceComponent::SetInvincibilityTime(float duration)
{
	isHittable = false;
	GetWorld()->GetTimerManager().SetTimer(invincibilityTimeHandle, this, &UYoruDefenceComponent::ChangeHittable, duration, false);
}

void UYoruDefenceComponent::ChangeHittable()
{
	isHittable = true;
}

void UYoruDefenceComponent::Block()
{
	if (me->currentPlayerState == EPlayerState::NONE)
	{
		me->moveComp->MovementInputHandler(0.0f, true);
		me->SetPlayerState(EPlayerState::Blocking);
		me->GetMesh()->GetAnimInstance()->Montage_Play(blockMontage);
	}
}

void UYoruDefenceComponent::UnBlock()
{
	isParrying = false;
	me->SetPlayerState(EPlayerState::NONE);
	me->moveComp->MovementInputHandler(0.2f, false);
	me->GetMesh()->GetAnimInstance()->Montage_Stop(0.2f, blockMontage);
}

void UYoruDefenceComponent::ChangeParrying()
{
	isParrying = !isParrying;
}

void UYoruDefenceComponent::InitAnimNotify()
{
	if (blockMontage)
	{
		TArray<FAnimNotifyEvent> notifyEvents{ blockMontage->Notifies };

		for (FAnimNotifyEvent eventNotify : notifyEvents)
		{
			if (UChangeParryingAnimNotify* startNotify = Cast<UChangeParryingAnimNotify>(eventNotify.Notify))
			{
				startNotify->onNotified.AddUObject(this, &UYoruDefenceComponent::ChangeParrying);
			}
		}
	}
}

bool UYoruDefenceComponent::CheckParrying() const noexcept
{
	return isParrying;
}

void UYoruDefenceComponent::CaculateBlock(float& damageAmount)
{
	if (me->statComp->CheckStamina(15.0f))
	{
		damageAmount /= 2;
		me->statComp->HandleStaminaRegen(false);
		me->statComp->DecreaseStamina(15.0f);
		me->statComp->HandleStaminaRegen(true, 0.75f);
	}
	else
	{
		UGameplayStatics::PlaySound2D(this, blockFailSound[0]);
		me->GetMesh()->GetAnimInstance()->Montage_Play(hitReactions[4]);
		UnBlock();
		damageAmount /= 2;
		me->statComp->HandleStaminaRegen(false);
		me->statComp->DecreaseStamina(15.0f);
		me->statComp->HandleStaminaRegen(true, 1.5f);
	}
}

bool UYoruDefenceComponent::Parry(float& damageAmount)
{
	if (me->statComp->CheckStamina(7.5f))
	{
		damageAmount = 0;
		me->statComp->HandleStaminaRegen(false);
		me->statComp->DecreaseStamina(7.5f);
		me->statComp->HandleStaminaRegen(true, 0.75f);
		return true;
	}

	return false;
}

void UYoruDefenceComponent::InitData()
{
	auto weaponSoundDataTable { me->GetGameInstance()->GetSubsystem<UTOMAudioSubsystem>()->weaponSoundDataTable };
	FWeaponSoundData* weaponSoundData{ weaponSoundDataTable->FindRow<FWeaponSoundData>(FName("GreatSword"), FString("")) };
	parryingSound = weaponSoundData->parryingSound;
	blockingSound = weaponSoundData->blockingSound;
	blockFailSound = weaponSoundData->blockFailSound;
	
	auto hurtSoundDataTable{ me->GetGameInstance()->GetSubsystem<UTOMAudioSubsystem>()->hurtSoundDataTable };
	FHurtSoundData* hurtSoundData{ hurtSoundDataTable->FindRow<FHurtSoundData>(FName("Player"), FString("")) };
	hurtSound = hurtSoundData->hurtSound;
	deadSound = hurtSoundData->deadSound;

}

void UYoruDefenceComponent::InitFX()
{
	parryingFX = LoadObject<UNiagaraSystem>(nullptr, TEXT("/Script/Niagara.NiagaraSystem'/Game/AAA/Effect/Niagara/NS_Parrying.NS_Parrying'"));

	blockingFX = LoadObject<UNiagaraSystem>(nullptr, TEXT("/Script/Niagara.NiagaraSystem'/Game/AAA/Effect/Niagara/NS_Blocking.NS_Blocking'"));
	bloodFX = LoadObject<UNiagaraSystem>(nullptr, TEXT("/Script/Niagara.NiagaraSystem'/Game/AAA/Effect/Niagara/NS_Blood.NS_Blood'"));
	parryingFootFX = LoadObject<UNiagaraSystem>(nullptr, TEXT("/Script/Niagara.NiagaraSystem'/Game/AAA/Effect/Niagara/NS_ParryingFoot.NS_ParryingFoot'"));
}

void UYoruDefenceComponent::ParryingBackMove()
{
	float initialSpeed = 600.0f;
	float decelerationRate = 0.98f;
	float currentSpeed = initialSpeed;

	UNiagaraFunctionLibrary::SpawnSystemAttached(parryingFootFX, me->GetMesh(), "foot_r", FVector::ZeroVector, FRotator::ZeroRotator, EAttachLocation::KeepRelativeOffset, true);
	UNiagaraFunctionLibrary::SpawnSystemAttached(parryingFootFX, me->GetMesh(), "foot_l", { 0.0,-30.0,0.0 }, {0.0,0.0,0.0}, EAttachLocation::KeepRelativeOffset, true);

	GetWorld()->GetTimerManager().SetTimer(parryingMoveTimeHandle, [this, currentSpeed, decelerationRate]() mutable
		{
			FVector currentLocation = me->GetActorLocation();
			FVector forwardVector = me->GetActorForwardVector().GetSafeNormal2D() * -1;
			FVector newLocation = currentLocation + forwardVector * currentSpeed * GetWorld()->GetDeltaSeconds();

			me->SetActorLocation(newLocation, true);

			currentSpeed *= decelerationRate;

			if (currentSpeed < 0.01f)
			{
				GetWorld()->GetTimerManager().ClearTimer(parryingMoveTimeHandle);
			}

		}, GetWorld()->GetDeltaSeconds(), true, 0.0f);
}

FVector UYoruDefenceComponent::CaculateParryPoint(const FVector& impactPoint)
{
	FVector target{};
	FVector point0{ me->equippedWeapon->weaponMesh->GetSocketLocation("ParryPoint_0") };
	FVector point1{ me->equippedWeapon->weaponMesh->GetSocketLocation("ParryPoint_1") };
	FVector point2{ me->equippedWeapon->weaponMesh->GetSocketLocation("ParryPoint_2") };

	double dist = std::abs(me->GetActorLocation().Z - 90.0 - impactPoint.Z);

	if (dist > 120.0)
	{
		return point2;
	}
	else if (dist > 90.0)
	{
		return point1;
	}
	else
	{
		return point0;
	}

	return point1;
}

