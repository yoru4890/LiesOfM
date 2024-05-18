// Fill out your copyright notice in the Description page of Project Settings.


#include "YoruPlayer/YoruDefenceComponent.h"
#include "TOMDataTable.h"
#include "YoruPlayer/Yoru.h"
#include "TOMGameInstance.h"
#include "YoruPlayer/YoruMoveComponent.h"
#include "YoruPlayer/YoruAttackComponent.h"

UYoruDefenceComponent::UYoruDefenceComponent()
{
}

void UYoruDefenceComponent::BeginPlay()
{
	Super::BeginPlay();
	
	
}

void UYoruDefenceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UYoruDefenceComponent::SetupPlayerInputComponent(UEnhancedInputComponent* enhancedInputComponent)
{

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
			me->GetMesh()->GetAnimInstance()->Montage_Play(temp[0]);
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
	}
}

void UYoruDefenceComponent::HandleHit()
{
	ChangeHittable();
	me->moveComp->MovementInputHandler(0.0f, true);
	me->attackComp->StopLineTrace();
	SetInvincibilityTime(1.0f);
}

void UYoruDefenceComponent::SetInvincibilityTime(float duration)
{
	GetWorld()->GetTimerManager().SetTimer(invincibilityTimeHandle, this, &UYoruDefenceComponent::ChangeHittable, duration, false);
}

void UYoruDefenceComponent::ChangeHittable()
{
	if (isHittable)
	{
		isHittable = false;
	}
	else
	{
		isHittable = true;
	}
}

