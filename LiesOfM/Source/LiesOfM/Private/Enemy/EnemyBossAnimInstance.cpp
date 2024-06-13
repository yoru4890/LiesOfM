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

	if (charMoveComp)
	{
		velocity = charMoveComp->Velocity;
		FVector direction{ owner->GetActorRotation().Vector() };
		FVector rightDirection{ FRotationMatrix(owner->GetActorRotation()).GetScaledAxis(EAxis::Y).GetSafeNormal2D() };
		FVector normalVelocity{ velocity.GetSafeNormal2D() };
		double dotResult{ FVector::DotProduct(direction, normalVelocity) };
		double rightDotResult{ FVector::DotProduct(rightDirection, normalVelocity) };
		double degree{ FMath::RadiansToDegrees(FMath::Acos(dotResult)) };
		if (rightDotResult < 0)
		{
			degree *= -1;
		}

		angle = degree;
		moveSpeed = velocity.Size2D();
	}
}
