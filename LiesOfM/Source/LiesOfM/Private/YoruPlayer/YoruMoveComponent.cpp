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
#include "Item/ItemBase.h"
#include "Components/CapsuleComponent.h"

UYoruMoveComponent::UYoruMoveComponent()
{
	InitFile();
	
}

void UYoruMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	SpawnWeapon();
	GetWorld()->GetTimerManager().SetTimer(spawnTimeHandle, this, &UYoruMoveComponent::SpawnItem, 0.5f, false);
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
	enhancedInputComponent->BindAction(useItemAction, ETriggerEvent::Started, this, &UYoruMoveComponent::UseItem);
	enhancedInputComponent->BindAction(interActAction, ETriggerEvent::Started, this, &UYoruMoveComponent::InterAction);
}

void UYoruMoveComponent::InitFile()
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

	static ConstructorHelpers::FObjectFinder<UInputAction> useItemActionFinder(TEXT("/Script/EnhancedInput.InputAction'/Game/AAA/Input/IA_UseItem.IA_UseItem'"));

	if (useItemActionFinder.Succeeded())
	{
		useItemAction = useItemActionFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> interActActionFinder(TEXT("/Script/EnhancedInput.InputAction'/Game/AAA/Input/IA_InterAction.IA_InterAction'"));

	if (interActActionFinder.Succeeded())
	{
		interActAction = interActActionFinder.Object;
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

	static ConstructorHelpers::FObjectFinder<UAnimMontage> useItemMontageFinder(TEXT("/Script/Engine.AnimMontage'/Game/AAA/Animations/Yoru/BaseMove/UseItem/AM_UsePortion.AM_UsePortion'"));

	if (useItemMontageFinder.Succeeded())
	{
		useItemMontage = useItemMontageFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> bossEnterMontageFinder(TEXT("/Script/Engine.AnimMontage'/Game/AAA/Animations/Yoru/BaseMove/BossEntrance/AM_BossEntrance.AM_BossEntrance'"));

	if (bossEnterMontageFinder.Succeeded())
	{
		bossEnterMontage = bossEnterMontageFinder.Object;
	}
}

void UYoruMoveComponent::Move(const FInputActionValue& value)
{
	if (!isMovementInput) return;

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
	if (me->GetMesh()->GetAnimInstance()->Montage_IsPlaying(useItemMontage)) return;
	if (me->isDie) return;
	if (!(me->isCanJump)) return;

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
		me->ChangeCamera(false);

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
		me->ChangeCamera(me->GetIsLockon());
		me->SetPlayerState(EPlayerState::NONE);
		me->statComp->HandleStaminaRegen(true, 0.75f);
	}
}

void UYoruMoveComponent::RollOrStepBack(const FInputActionValue& value)
{
	if (me->GetMesh()->GetAnimInstance()->Montage_IsPlaying(useItemMontage)) return;
	if (me->isDie) return;

	if (isMovementInput && me->statComp->CheckStamina(8.0f))
	{
		charMoveComp->MaxWalkSpeed = me->GetStatComp()->jogSpeed;
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
	if (me->GetMesh()->GetAnimInstance()->IsAnyMontagePlaying()) return;
	if (me->isDie) return;

	if (!HasMovementKeyInput())
	{
		if (isUseRightWeapon)
		{
			me->widgetComp->SetVisiblerightWeapon(false);
			me->GetMesh()->GetAnimInstance()->Montage_Play(unEquipMontage);
			GetWorld()->GetTimerManager().SetTimer(equipTimeHandle, this, &UYoruMoveComponent::UnEquipRightWeapon, 0.5f, false);
		}
		else
		{
			if (isHaveRightWeapon)
			{
				me->widgetComp->SetVisiblerightWeapon(true);
				me->GetMesh()->GetAnimInstance()->Montage_Play(equipMontage);
				EquipRightWeapon();
			}
		}
	}
}

void UYoruMoveComponent::InterAction(const FInputActionValue& value)
{
	if (me->GetMesh()->GetAnimInstance()->Montage_IsPlaying(useItemMontage)) return;
	if (me->isDie) return;

	if (canBossEnter)
	{
		me->SetActorRotation({0,-8.0,0});
		MovementInputHandler(0.0f, true);
		me->defenceComp->SetInvincibilityTime(2.5f);
		me->equippedWeapon->weaponMesh->SetVisibility(false);
		me->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		me->GetMesh()->GetAnimInstance()->Montage_Play(bossEnterMontage);
		
		GetWorld()->GetTimerManager().SetTimer(bossEnterTimeHandle, [this]()
			{
				me->SetActorLocation(FMath::VInterpTo(me->GetActorLocation(), me->GetActorLocation() + me->GetActorForwardVector() * 100.0f, 0.01f, 1.5f));
			}, 0.01f, true);
	}
}

void UYoruMoveComponent::UseItem()
{
	if (me->GetMesh()->GetAnimInstance()->IsAnyMontagePlaying()) return;
	if (me->isDie) return;

	if (!portionCount) return;

	if (!HasMovementKeyInput())
	{
		MovementInputHandler(0.0f, true);
		me->GetMesh()->GetAnimInstance()->Montage_Play(useItemMontage);
		MovementInputHandler(0.5f, false);
	}
}

void UYoruMoveComponent::Die()
{
	me->isDie = true;
	me->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MovementInputHandler(0.0f, true);
	me->widgetComp->AddToViewDie();
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
		me->ChangeCamera(false);
		me->SetPlayerState(EPlayerState::Rolling);
		GetWorld()->GetTimerManager().SetTimer(rollTimeHandle, [this]()
			{
				me->SetActorLocation(FMath::VInterpTo(me->GetActorLocation(), me->GetActorLocation() + me->GetActorForwardVector() * rollDistance, GetWorld()->GetDeltaSeconds(), rollMoveSpeed));
			}, 0.01f, true);
		
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

void UYoruMoveComponent::ShowItem()
{
	me->equippedItem->itemMesh->SetVisibility(true);
}

void UYoruMoveComponent::HiddenItem()
{
	me->equippedItem->itemMesh->SetVisibility(false);
}

void UYoruMoveComponent::CaculatePortion()
{
	portionCount--;
	me->statComp->hpRegen = 0.2f;
	me->statComp->HandleHPRegen(true);
	GetWorld()->GetTimerManager().SetTimer(HPTimeHandle, this, &UYoruMoveComponent::StopCaculatePortion, 1.0f, false);
}

void UYoruMoveComponent::StopCaculatePortion()
{
	me->statComp->hpRegen = 0.0f;
	me->statComp->HandleHPRegen(false);
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

void UYoruMoveComponent::SpawnItem()
{
	UObject* spawnActor = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Script/Engine.Blueprint'/Game/AAA/Blueprints/Item/BP_Item.BP_Item'")));

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

	FTransform tempTransform{ me->GetMesh()->GetSocketTransform(TEXT("hand_rSocket_Item")) };

	FActorSpawnParameters spawnParams;
	spawnParams.Owner = me;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	me->equippedItem = GetWorld()->SpawnActor<AItemBase>(generatedBP->GeneratedClass, tempTransform, spawnParams);

	me->equippedItem->AttachToComponent(me->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("hand_rSocket_Item"));
	HiddenItem();
}

void UYoruMoveComponent::StopRollMove()
{
	GetWorld()->GetTimerManager().ClearTimer(rollTimeHandle);
}

void UYoruMoveComponent::StopBossEnter()
{
	GetWorld()->GetTimerManager().ClearTimer(bossEnterTimeHandle);
	me->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	me->equippedWeapon->weaponMesh->SetVisibility(true);
	canBossEnter = false;
	MovementInputHandler(0.0f, false);
}

