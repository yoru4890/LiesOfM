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
#include "Weapon/WeaponBase.h"
#include "YoruPlayer/YoruDefenceComponent.h"

UYoruMoveComponent::UYoruMoveComponent()
{

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

	static ConstructorHelpers::FObjectFinder<UInputAction> crouchActionFinder(TEXT("/Script/EnhancedInput.InputAction'/Game/AAA/Input/IA_YoruCrouch.IA_YoruCrouch'"));

	if (crouchActionFinder.Succeeded())
	{
		crouchAction = crouchActionFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> changeWeaponActionFinder(TEXT("/Script/EnhancedInput.InputAction'/Game/AAA/Input/IA_ChangeWeapon.IA_ChangeWeapon'"));

	if (changeWeaponActionFinder.Succeeded())
	{
		changeWeaponAction = changeWeaponActionFinder.Object;
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

	static ConstructorHelpers::FObjectFinder<UAnimMontage> equipMontageFinder(TEXT("/Script/Engine.AnimMontage'/Game/AAA/Animations/Yoru/GreatSwordMove/AM_GreatSwordEquip.AM_GreatSwordEquip'"));

	if (equipMontageFinder.Succeeded())
	{
		equipMontage = equipMontageFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> unEquipMontageFinder(TEXT("/Script/Engine.AnimMontage'/Game/AAA/Animations/Yoru/GreatSwordMove/AM_GreatSwordUnEquip.AM_GreatSwordUnEquip'"));

	if (unEquipMontageFinder.Succeeded())
	{
		unEquipMontage = unEquipMontageFinder.Object;
	}
}

void UYoruMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	SpawnWeapon();
}

void UYoruMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

void UYoruMoveComponent::SetupPlayerInputComponent(UEnhancedInputComponent* enhancedInputComponent)
{
	enhancedInputComponent->BindAction(moveAction, ETriggerEvent::Triggered, this, &UYoruMoveComponent::Move);
	enhancedInputComponent->BindAction(moveAction, ETriggerEvent::Canceled, this, &UYoruMoveComponent::NoMove);
	enhancedInputComponent->BindAction(moveAction, ETriggerEvent::Completed, this, &UYoruMoveComponent::NoMove);
	enhancedInputComponent->BindAction(lookAction, ETriggerEvent::Triggered, this, &UYoruMoveComponent::Look);
	enhancedInputComponent->BindAction(jumpAction, ETriggerEvent::Started, this, &UYoruMoveComponent::Jump);
	enhancedInputComponent->BindAction(moveChangeAction, ETriggerEvent::Triggered, this, &UYoruMoveComponent::ChangeWalk);
	enhancedInputComponent->BindAction(moveChangeAction, ETriggerEvent::Completed, this, &UYoruMoveComponent::ChangeJog);
	enhancedInputComponent->BindAction(runRollAction, ETriggerEvent::Triggered, this, &UYoruMoveComponent::Run);
	enhancedInputComponent->BindAction(runRollAction, ETriggerEvent::Completed, this, &UYoruMoveComponent::StopRunning);
	enhancedInputComponent->BindAction(runRollAction, ETriggerEvent::Canceled, this, &UYoruMoveComponent::RollOrStepBack);
	enhancedInputComponent->BindAction(crouchAction, ETriggerEvent::Started, this, &UYoruMoveComponent::ChangeCrouch);
	enhancedInputComponent->BindAction(changeWeaponAction, ETriggerEvent::Started, this, &UYoruMoveComponent::ChangeWeapon);
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
	if (me->GetIsLockon()) return;
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
	if (me->GetPlayerState() == EPlayerState::Crouch)
	{
		ChangeCrouch(value);
	}
	else
	{
		me->Jump();
	}
}

void UYoruMoveComponent::ChangeWalk(const FInputActionValue& value)
{
	if (me->currentPlayerState == EPlayerState::Crouch)
	{
		return;
	}

	if (isMovementInput && me->GetPlayerState() != EPlayerState::Running)
	{
		charMoveComp->MaxWalkSpeed = me->GetStatComp()->walkSpeed;
	}
}

void UYoruMoveComponent::ChangeJog(const FInputActionValue& value)
{
	if (me->currentPlayerState == EPlayerState::Crouch)
	{
		return;
	}

	if (isMovementInput && me->GetPlayerState() != EPlayerState::Running)
	{
		charMoveComp->MaxWalkSpeed = me->GetStatComp()->jogSpeed;
	}
}

void UYoruMoveComponent::Run(const FInputActionValue& value)
{
	if (me->currentPlayerState == EPlayerState::Crouch)
	{
		return;
	}
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
	if (me->currentPlayerState == EPlayerState::Crouch)
	{
		return;
	}
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
		me->defenceComp->ChangeHittable();
		me->statComp->HandleStaminaRegen(false, 0.75f);
		HandleRollStepBack();
		me->statComp->CallUpdateStamina();
	}
}

void UYoruMoveComponent::ChangeCrouch(const FInputActionValue& value)
{
	if (!HasMovementKeyInput())
	{
		if (me->GetPlayerState() != EPlayerState::Crouch)
		{
			me->SetPlayerState(EPlayerState::Crouch);
			charMoveComp->MaxWalkSpeed = me->GetStatComp()->walkSpeed;
		}
		else
		{
			me->SetPlayerState(EPlayerState::NONE);
			charMoveComp->MaxWalkSpeed = me->GetStatComp()->jogSpeed;
		}
	}

}

void UYoruMoveComponent::ChangeWeapon(const FInputActionValue& value)
{
	if (!HasMovementKeyInput())
	{
		if (isUseRightWeapon)
		{
			me->GetMesh()->GetAnimInstance()->Montage_Play(unEquipMontage);
			GetWorld()->GetTimerManager().SetTimer(equipTimeHandle, this, &UYoruMoveComponent::UnEquipRightWeapon, 0.5f, false);
		}
		else
		{
			if (isHaveRightWeapon)
			{
				me->GetMesh()->GetAnimInstance()->Montage_Play(equipMontage);
				EquipRightWeapon();
			}
		}
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
		me->defenceComp->SetInvincibilityTime(0.6f);
		me->SetActorRotation({ 0,charMoveComp->GetLastInputVector().ToOrientationRotator().Yaw,0 });
		me->statComp->HandleStaminaRegen(true, 0.75f);
	}
	else
	{
		me->SetPlayerState(EPlayerState::StepBack);
		me->GetMesh()->GetAnimInstance()->Montage_Play(stepBackMontage);
		me->defenceComp->SetInvincibilityTime(0.6f);
		me->statComp->HandleStaminaRegen(true, 0.75f);
	}
}

void UYoruMoveComponent::SetMovementInputTrue()
{
	isMovementInput = true;
	me->currentPlayerState = EPlayerState::NONE;
}

void UYoruMoveComponent::EquipRightWeapon()
{
	isUseRightWeapon = true;
	me->currentRightWeaponState = EUseWeaponState::GREATSWORD;
	me->equippedWeapon->weaponMesh->SetVisibility(true);
}

void UYoruMoveComponent::UnEquipRightWeapon()
{
	isUseRightWeapon = false;
	me->currentRightWeaponState = EUseWeaponState::NONE;
	me->equippedWeapon->weaponMesh->SetVisibility(false);
}

void UYoruMoveComponent::SpawnWeapon()
{
	UObject* spawnActor = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Script/Engine.Blueprint'/Game/AAA/Blueprints/Weapon/BP_Weapon.BP_Weapon'")));

	UBlueprint* generatedBP = Cast<UBlueprint>(spawnActor);

	if (!spawnActor)
	{
		return;
	}

	UClass* spawnClass = spawnActor->StaticClass();

	if (!spawnClass)
	{
		return;
	}

	FTransform tempTransform{ me->GetMesh()->GetSocketTransform(TEXT("hand_rSocket_GreatSword")) };

	FActorSpawnParameters spawnParams;
	spawnParams.Owner = me;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	me->equippedWeapon = GetWorld()->SpawnActor<AWeaponBase>(generatedBP->GeneratedClass, tempTransform, spawnParams);

	me->equippedWeapon->AttachToComponent(me->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("hand_rSocket_GreatSword"));
}
