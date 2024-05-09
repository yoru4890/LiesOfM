// Fill out your copyright notice in the Description page of Project Settings.


#include "YoruPlayer/YoruMoveComponent.h"
#include "YoruPlayer/Yoru.h"
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include <InputMappingContext.h>
#include "Kismet/KismetMathLibrary.h"
#include "YoruPlayer/YoruStatComponent.h"


UYoruMoveComponent::UYoruMoveComponent()
{
	static ConstructorHelpers::FObjectFinder<UInputMappingContext> iMContextFinder(TEXT("/Script/EnhancedInput.InputMappingContext'/Game/AAA/Input/IMC_Yoru.IMC_Yoru'"));

	if (iMContextFinder.Succeeded())
	{
		defaultInputMappingContext = iMContextFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> moveActionFinder(TEXT("/Script/EnhancedInput.InputAction'/Game/AAA/Input/IA_YoruMove.IA_YoruMove'"));

	if (moveActionFinder.Succeeded())
	{
		moveAction = moveActionFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> lookActionFinder(TEXT("/Script/EnhancedInput.InputAction'/Game/AAA/Input/IA_YoruLook.IA_YoruLook'"));

	if (lookActionFinder.Succeeded())
	{
		lookAction = lookActionFinder.Object;
	}

}

void UYoruMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* playerController = Cast<APlayerController>(me->GetController());
	if (playerController)
	{
		UEnhancedInputLocalPlayerSubsystem* subSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer());

		if (subSystem)
		{
			subSystem->AddMappingContext(defaultInputMappingContext, 0);
		}
	}

}

void UYoruMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

void UYoruMoveComponent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	UEnhancedInputComponent* enhancedInputComponet = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	enhancedInputComponet->BindAction(moveAction, ETriggerEvent::Triggered, this, &UYoruMoveComponent::Move);
	enhancedInputComponet->BindAction(lookAction, ETriggerEvent::Triggered, this, &UYoruMoveComponent::Look);
}

void UYoruMoveComponent::Move(const FInputActionValue& value)
{
	FRotator controlRotation{ me->GetControlRotation() };
	controlRotation.Pitch = 0;
	me->AddMovementInput(UKismetMathLibrary::GetRightVector(controlRotation), value.Get<FVector2D>().X);
	controlRotation.Roll = 0;
	me->AddMovementInput(UKismetMathLibrary::GetForwardVector(controlRotation), value.Get<FVector2D>().Y);
}

void UYoruMoveComponent::Look(const FInputActionValue& value)
{
	double valueX{ value.Get<FVector2D>().X };
	double valueY{ value.Get<FVector2D>().Y };
	double controlPitch{ me->GetControlRotation().Pitch };
	me->AddControllerYawInput(valueX * me->GetWorld()->DeltaTimeSeconds * mouseSpeed);

	if (controlPitch >= 50 && controlPitch <= 90)
	{
		if (value.Get<FVector2D>().Y > 0)
		{
			me->AddControllerPitchInput(valueY * me->GetWorld()->DeltaTimeSeconds * mouseSpeed);
		}
	}
	else if (controlPitch >= 270 && controlPitch <= 310)
	{
		if (value.Get<FVector2D>().Y < 0)
		{
			me->AddControllerPitchInput(valueY * me->GetWorld()->DeltaTimeSeconds * mouseSpeed);
		}
	}
	else
	{
		me->AddControllerPitchInput(valueY * me->GetWorld()->DeltaTimeSeconds * mouseSpeed);
	}
}
