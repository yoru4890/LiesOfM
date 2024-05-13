// Fill out your copyright notice in the Description page of Project Settings.


#include "YoruPlayer/YoruAnimInstance.h"
#include "YoruPlayer/Yoru.h"
#include "GameFramework/CharacterMovementComponent.h"

UYoruAnimInstance::UYoruAnimInstance()
{
}

void UYoruAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	owner = Cast<AYoru>(GetOwningActor());
	if (owner)
	{
		charMoveComp = owner->GetCharacterMovement();
	}
}

void UYoruAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (charMoveComp)
	{
		isPressedMovementInput = owner->GetisPressedMovementInput();
		velocity = charMoveComp->Velocity;
		moveSpeed = velocity.Size2D();
		isFalling = charMoveComp->IsFalling();
		if (charMoveComp->MaxWalkSpeed == 150.0f)
		{
			isWalking = true;
		}
		else
		{
			isWalking = false;
		}

		if (owner->GetPlayerState() == EPlayerState::Crouch)
		{
			isCrouch = true;
		}
		else
		{
			isCrouch = false;
		}
	}
}
