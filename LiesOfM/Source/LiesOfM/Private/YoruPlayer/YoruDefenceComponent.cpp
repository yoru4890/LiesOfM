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

void UYoruDefenceComponent::HitReaction(float damageAmount, AActor* attackingActor, const FHitResult& hitResult)
{
	if (isHittable)
	{
		HandleHit();

		FPlayerData* hitReactionAnimData = me->singleGameInstance->playerDataTable->FindRow<FPlayerData>(me->GetDataTableRowNames()[0], FString(""));
		TArray<UAnimMontage*> temp = hitReactionAnimData->hitReactionMontages;
		FVector actorDirection{ me->GetActorRotation().Vector().GetSafeNormal2D() };
		FVector actorRightDirection{ (FRotationMatrix(me->GetActorRotation()).GetScaledAxis(EAxis::Y)).GetSafeNormal2D() };
		FVector hitDirection{ (hitResult.ImpactPoint - me->GetActorLocation()).GetSafeNormal2D() };
		double rightDotResult{ FVector::DotProduct(actorRightDirection, hitDirection) };
		double angle{ FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(actorDirection, hitDirection))) };
		if (rightDotResult < 0)
		{
			angle *= -1;
		}

		if (angle <= 45.0f && angle >= -45.0f)
		{
			if (isParrying)
			{
				if (!Parry())
				{
					me->GetMesh()->GetAnimInstance()->Montage_Play(temp[0]);
				}
			}
			else if (me->GetPlayerState() == EPlayerState::Blocking)
			{
				CaculateBlock(damageAmount);
			}
			else
			{
				me->GetMesh()->GetAnimInstance()->Montage_Play(temp[0]);
			}
		}
		else if (angle > 45.0f && angle <= 135.0f)
		{
			me->GetMesh()->GetAnimInstance()->Montage_Play(temp[1]);
		}
		else if (angle < -45.0f && angle >= -135.0f)
		{
			me->GetMesh()->GetAnimInstance()->Montage_Play(temp[3]);
		}
		else
		{
			me->GetMesh()->GetAnimInstance()->Montage_Play(temp[2]);
		}

		me->statComp->DecreaseHP(damageAmount);
	}
}

void UYoruDefenceComponent::HandleHit()
{
	me->moveComp->MovementInputHandler(0.0f, true);
	me->attackComp->StopLineTrace();
	SetInvincibilityTime(1.0f);
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
		me->SetPlayerState(EPlayerState::Blocking);
		me->GetMesh()->GetAnimInstance()->Montage_Play(blockMontage);
	}
}

void UYoruDefenceComponent::UnBlock()
{
	isParrying = false;
	me->SetPlayerState(EPlayerState::NONE);
	me->GetMesh()->GetAnimInstance()->Montage_Stop(0.2f, blockMontage);
}

void UYoruDefenceComponent::ChangeParrying()
{
	isParrying = !isParrying;
	UE_LOG(LogTemp, Warning, TEXT("%d"), isParrying);
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
		damageAmount /= 2;
		me->statComp->HandleStaminaRegen(false);
		me->statComp->DecreaseStamina(15.0f);
		me->statComp->HandleStaminaRegen(true, 1.5f);
	}
}

bool UYoruDefenceComponent::Parry()
{
	if (me->statComp->CheckStamina(7.5f))
	{
		me->statComp->HandleStaminaRegen(false);
		me->statComp->DecreaseStamina(7.5f);
		me->statComp->HandleStaminaRegen(true, 0.75f);
		UE_LOG(LogTemp, Warning, TEXT("Parry"));
		return true;
	}

	return false;
}

