// Fill out your copyright notice in the Description page of Project Settings.


#include "YoruPlayer/YoruMoveComponent.h"
#include "YoruPlayer/Yoru.h"
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include <InputMappingContext.h>
#include "Kismet/KismetMathLibrary.h"
#include "YoruPlayer/YoruStatComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


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

	static ConstructorHelpers::FObjectFinder<UInputAction> jumpActionFinder(TEXT("/Script/EnhancedInput.InputAction'/Game/AAA/Input/IA_YoruJump.IA_YoruJump'"));

	if (jumpActionFinder.Succeeded())
	{
		jumpAction = jumpActionFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> moveChangeActionFinder(TEXT("/Script/EnhancedInput.InputAction'/Game/AAA/Input/IA_YoruMoveChane.IA_YoruMoveChane'"));

	if (moveChangeActionFinder.Succeeded())
	{
		moveChangeAction = moveChangeActionFinder.Object;
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
	enhancedInputComponet->BindAction(moveAction, ETriggerEvent::Canceled, this, &UYoruMoveComponent::NoMove);
	enhancedInputComponet->BindAction(moveAction, ETriggerEvent::Completed, this, &UYoruMoveComponent::NoMove);
	enhancedInputComponet->BindAction(lookAction, ETriggerEvent::Triggered, this, &UYoruMoveComponent::Look);
	enhancedInputComponet->BindAction(jumpAction, ETriggerEvent::Started, this, &UYoruMoveComponent::Jump);
	enhancedInputComponet->BindAction(moveChangeAction, ETriggerEvent::Triggered, this, &UYoruMoveComponent::ChangeWalk);
	enhancedInputComponet->BindAction(moveChangeAction, ETriggerEvent::Completed, this, &UYoruMoveComponent::ChangeRun);
}

void UYoruMoveComponent::Move(const FInputActionValue& value)
{
	me->SetisPressedMovementInput(true);
	
	elapsedTimePressedMove += me->GetWorld()->DeltaTimeSeconds;
	

	UE_LOG(LogTemp, Warning, TEXT("%f"), elapsedTimePressedMove);

	moveSpeed = FMath::Clamp(elapsedTimePressedMove, 0.3f, 1.0f);

	FRotator controlRotation{ me->GetControlRotation() };
	controlRotation.Pitch = 0;
	me->AddMovementInput(UKismetMathLibrary::GetRightVector(controlRotation), value.Get<FVector2D>().X * moveSpeed);
	controlRotation.Roll = 0;
	me->AddMovementInput(UKismetMathLibrary::GetForwardVector(controlRotation), value.Get<FVector2D>().Y * moveSpeed);
}

void UYoruMoveComponent::NoMove(const FInputActionValue& value)
{
	me->SetisPressedMovementInput(false);
	elapsedTimePressedMove = 0;
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
	else if (controlPitch >= 270 && controlPitch <= 300)
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

void UYoruMoveComponent::Jump(const FInputActionValue& value)
{
	me->Jump();
}

void UYoruMoveComponent::ChangeWalk(const FInputActionValue& value)
{
	me->GetCharacterMovement()->MaxWalkSpeed = me->GetStatComp()->walkSpeed;
}

void UYoruMoveComponent::ChangeRun(const FInputActionValue& value)
{
	me->GetCharacterMovement()->MaxWalkSpeed = me->GetStatComp()->runSpeed;
}
