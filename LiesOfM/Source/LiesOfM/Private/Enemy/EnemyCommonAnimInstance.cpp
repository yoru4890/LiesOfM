// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyCommonAnimInstance.h"
#include "Enemy/EnemyCommon.h"
#include "GameFramework/CharacterMovementComponent.h"

UEnemyCommonAnimInstance::UEnemyCommonAnimInstance()
{
}

void UEnemyCommonAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	owner = Cast<AEnemyCommon>(GetOwningActor());
	if (owner)
	{
		charMoveComp = owner->GetCharacterMovement();
	}
}

void UEnemyCommonAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
}
