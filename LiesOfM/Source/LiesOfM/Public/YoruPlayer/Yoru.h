// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/DamageInteractions.h"
#include "Yoru.generated.h"

UENUM(BlueprintType)
enum class EPlayerState : uint8
{ 
	NONE UMETA(DisplayName = "NONE"),
	Running UMETA(DisplayName = "Running"),
	Rolling UMETA(DisplayName = "Rolling"),
	StepBack UMETA(DisplayName = "StepBack"),
	Crouch UMETA(DisplayName = "Crouch"),
	LightAttack UMETA(DisplayName = "LightAttack"),
	HeavyAttack UMETA(DisplayName = "HeavyAttack"),
	RunningAttack UMETA(DisplayName = "RunningAttack"),
	RollingAttack UMETA(DisplayName = "RollingAttack"),
	BackStab UMETA(DisplayName = "BackStab"),
	Riposte UMETA(DisplayName = "Riposte"),

	SIZE
};

UENUM(BlueprintType)
enum class EUseWeaponState : uint8
{
	NONE UMETA(DisplayName = "NONE"),
	GREATSWORD UMETA(DisplayName = "GREATSWORD"),

	SIZE
};


UCLASS()
class LIESOFM_API AYoru : public ACharacter, public IDamageInteractions
{
	GENERATED_BODY()

public:
	AYoru();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


public:
	inline TObjectPtr<class UYoruStatComponent> GetStatComp() const noexcept { return statComp; }

	UFUNCTION(BlueprintCallable)
	inline bool GetisPressedMovementInput() const noexcept { return isPressedMovementInput; }
	UFUNCTION(BlueprintCallable)
	inline void SetisPressedMovementInput(bool isPressed) { isPressedMovementInput = isPressed; }

	EPlayerState GetPlayerState() const noexcept { return currentPlayerState; }
	UFUNCTION(BlueprintCallable, Category = Test)
	void SetPlayerState(const TEnumAsByte<EPlayerState>& state);
public:
	UPROPERTY(BlueprintReadWrite, Category = "Yoru|Compoent")
	TObjectPtr<class USpringArmComponent> mainSpringArmComp{};

	UPROPERTY(BlueprintReadWrite, Category = "Yoru|Compoent")
	TObjectPtr<class UCameraComponent> mainCamera{};

	//UPROPERTY(BlueprintReadWrite, Category = "Yoru|Compoent")
	//TObjectPtr<class USkeletalMeshComponent> rightWeapon{};

	UPROPERTY(BlueprintReadWrite, Category = "Yoru|Component")
	TObjectPtr<class UYoruMoveComponent> moveComp{};

	UPROPERTY(BlueprintReadWrite, Category = "Yoru|Component")
	TObjectPtr<class UYoruStatComponent> statComp{};

	UPROPERTY(BlueprintReadWrite, Category = "Yoru|Component")
	TObjectPtr<class UYoruWidgetComponent> widgetComp{};

	UPROPERTY(BlueprintReadWrite, Category = "Yoru|Component")
	TObjectPtr<class UYoruAttackComponent> attackComp{};

	UPROPERTY(BlueprintReadWrite, Category = "Yoru|Component")
	TObjectPtr<class UYoruDefenceComponent> defenceComp{};

	UPROPERTY(BlueprintReadWrite, Category = "Yoru|Component")
	TObjectPtr<class UYoruLockonComponent> lockonComp{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Yoru|Component")
	TObjectPtr<class UWidgetComponent> lockonWidget{};

	UPROPERTY(BlueprintReadWrite)
	EPlayerState currentPlayerState{ EPlayerState::NONE };

	UPROPERTY(BlueprintReadWrite)
	EUseWeaponState currentRightWeaponState{ EUseWeaponState::GREATSWORD };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Yoru|Weapon")
	class AWeaponBase* equippedWeapon{};

	UPROPERTY(VisibleAnywhere, Category = "Yoru|Input")
	TObjectPtr<class UInputMappingContext> defaultInputMappingContext;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Yoru|Utility")
	class UTOMGameInstance* singleGameInstance;

	UFUNCTION(BlueprintCallable)
	virtual void ReceiveDamage(float damageAmount, AActor* attackingActor, const FHitResult& hitResult) override;

	TArray<FName> GetDataTableRowNames() const noexcept { return dataTableRowNames; }

	UFUNCTION(BlueprintCallable)
	bool GetIsLockon() const noexcept { return isLockon; }

	UFUNCTION(BlueprintCallable)
	void SetIsLockon(bool lockon) { isLockon = lockon; }

private:
	UPROPERTY(VisibleAnywhere, Category = "Yoru|Input")
	bool isPressedMovementInput{};

	UPROPERTY(VisibleAnywhere, Category = "Yoru|DataTable")
	TArray<FName> dataTableRowNames{};

	UPROPERTY(VisibleAnywhere, Category = "Yoru|Input")
	bool isLockon{};
};
