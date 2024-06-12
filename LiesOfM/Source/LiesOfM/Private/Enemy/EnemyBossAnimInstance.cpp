// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyBossAnimInstance.h"
#include "Enemy/EnemyBoss.h"
#include "GameFramework/CharacterMovementComponent.h"

UEnemyBossAnimInstance::UEnemyBossAnimInstance()
{
}

void UEnemyBossAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	owner = Cast<AEnemyBoss>(GetOwningActor());
	if (owner)
	{
		charMoveComp = owner->GetCharacterMovement();
	}
}

void UEnemyBossAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
}
