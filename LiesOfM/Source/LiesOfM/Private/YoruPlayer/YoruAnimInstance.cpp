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
		moveComp = owner->GetCharacterMovement();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AnimInstance doesn't get Onwer"));
	}
}

void UYoruAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (moveComp)
	{
		isPressedMovementInput = owner->GetisPressedMovementInput();
		velocity = moveComp->Velocity;
		moveSpeed = velocity.Size2D();

		isFalling = moveComp->IsFalling();
	}
}
