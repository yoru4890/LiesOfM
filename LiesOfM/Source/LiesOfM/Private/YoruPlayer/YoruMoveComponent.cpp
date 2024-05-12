// Fill out your copyright notice in the Description page of Project Settings.


#include "YoruPlayer/YoruMoveComponent.h"
#include "YoruPlayer/Yoru.h"
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include <InputMappingContext.h>
#include "Kismet/KismetMathLibrary.h"
#include "YoruPlayer/YoruStatComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "YoruPlayer/YoruWidgetComponent.h"


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

	static ConstructorHelpers::FObjectFinder<UInputAction> runRollActionFinder(TEXT("/Script/EnhancedInput.InputAction'/Game/AAA/Input/IA_Yoru_Run_Roll.IA_Yoru_Run_Roll'"));

	if (runRollActionFinder.Succeeded())
	{
		runRollAction = runRollActionFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> rollingMontageFinder(TEXT("/Script/Engine.AnimMontage'/Game/AAA/Animations/Yoru/BaseMove/Roll/AM_Rolling.AM_Rolling'"));

	if (rollingMontageFinder.Succeeded())
	{
		rollingMontage = rollingMontageFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> stepBackMontageFinder(TEXT("/Script/Engine.AnimMontage'/Game/AAA/Animations/Yoru/BaseMove/Roll/AM_StepBack.AM_StepBack'"));

	if (stepBackMontageFinder.Succeeded())
	{
		stepBackMontage = stepBackMontageFinder.Object;
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
	enhancedInputComponet->BindAction(moveChangeAction, ETriggerEvent::Completed, this, &UYoruMoveComponent::ChangeJog);
	enhancedInputComponet->BindAction(runRollAction, ETriggerEvent::Triggered, this, &UYoruMoveComponent::Run);
	enhancedInputComponet->BindAction(runRollAction, ETriggerEvent::Completed, this, &UYoruMoveComponent::StopRunning);
	enhancedInputComponet->BindAction(runRollAction, ETriggerEvent::Canceled, this, &UYoruMoveComponent::RollOrStepBack);
}

void UYoruMoveComponent::Move(const FInputActionValue& value)
{
	me->SetisPressedMovementInput(true);
	
	elapsedTimePressedMove += me->GetWorld()->DeltaTimeSeconds;

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
	if (isMovementInput && me->GetPlayerState() != EPlayerState::Running)
	{
		charMoveComp->MaxWalkSpeed = me->GetStatComp()->walkSpeed;
	}
}

void UYoruMoveComponent::ChangeJog(const FInputActionValue& value)
{
	if (isMovementInput && me->GetPlayerState() != EPlayerState::Running)
	{
		charMoveComp->MaxWalkSpeed = me->GetStatComp()->jogSpeed;
	}
}

void UYoruMoveComponent::Run(const FInputActionValue& value)
{
	if (isMovementInput && HasMovementKeyInput())
	{
		if (me->GetPlayerState() == EPlayerState::Running)
		{
			me->statComp->RunTick();
		}
		else
		{
			if (me->statComp->CheckStamina(30.0f))
			{
				me->statComp->HandleStaminaRegen(false, 0.75f);
				charMoveComp->MaxWalkSpeed = me->statComp->runSpeed;
				me->SetPlayerState(EPlayerState::Running);
			}
		}
	}
	else
	{
		StopRunning();
	}
}

bool UYoruMoveComponent::HasMovementKeyInput() const
{
	return charMoveComp->GetLastInputVector() != FVector::ZeroVector;
}

void UYoruMoveComponent::StopRunning()
{
	charMoveComp->MaxWalkSpeed = me->statComp->jogSpeed;

	if (!(me->GetMesh()->GetAnimInstance()->IsAnyMontagePlaying()))
	{
		me->SetPlayerState(EPlayerState::NONE);
		me->statComp->HandleStaminaRegen(true, 0.75f);
	}
}

void UYoruMoveComponent::RollOrStepBack(const FInputActionValue& value)
{
	if (isMovementInput && me->statComp->CheckStamina(8.0f))
	{
		me->statComp->HandleStaminaRegen(false, 0.75f);
		HandleRollStepBack();
		me->statComp->CallUpdateStamina();
	}
}

void UYoruMoveComponent::MovementInputHandler(float duration, bool isStopInput)
{
	if (isStopInput)
	{
		isMovementInput = false;
	}
	else
	{
		GetWorld()->GetTimerManager().ClearTimer(inputTimeHandle);
		GetWorld()->GetTimerManager().SetTimer(inputTimeHandle, this, &UYoruMoveComponent::SetMovementInputTrue, 0.1f, false,duration);
	}
}

void UYoruMoveComponent::HandleRollStepBack()
{
	MovementInputHandler(0.0f, true);
	me->statComp->DecreaseStamina(15.0f);

	if (HasMovementKeyInput())
	{
		me->SetPlayerState(EPlayerState::Rolling);
		me->GetMesh()->GetAnimInstance()->Montage_Play(rollingMontage);
		me->SetActorRotation({ 0,charMoveComp->GetLastInputVector().ToOrientationRotator().Yaw,0 });
		me->statComp->HandleStaminaRegen(true, 0.75f);
	}
	else
	{
		me->SetPlayerState(EPlayerState::StepBack);
		me->GetMesh()->GetAnimInstance()->Montage_Play(stepBackMontage);
		me->statComp->HandleStaminaRegen(true, 0.75f);
	}
}
