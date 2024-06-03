// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "YoruPlayer/YoruBaseComponent.h"
#include "InputActionvalue.h"
#include "YoruMoveComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class LIESOFM_API UYoruMoveComponent : public UYoruBaseComponent
{
	GENERATED_BODY()
	

public:
	UYoruMoveComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void SetupPlayerInputComponent(class UEnhancedInputComponent* enhancedInputComponent) override;

public:
	void InitFile();
	void Move(const FInputActionValue& value);
	void NoMove(const FInputActionValue& value);
	void Look(const FInputActionValue& value);
	void Jump(const FInputActionValue& value);
	void ChangeWalk(const FInputActionValue& value);
	void ChangeJog(const FInputActionValue& value);
	void Run(const FInputActionValue& value);
	void StopRunning();
	void RollOrStepBack(const FInputActionValue& value);
	void ChangeCrouch(const FInputActionValue& value);
	void ChangeWeapon(const FInputActionValue& value);
	void UseItem();

	UFUNCTION(BlueprintCallable)
	void MovementInputHandler(float duration, bool isStopInput);
	void HandleRollStepBack();
	void SetMovementInputTrue();

	UFUNCTION(BlueprintCallable)
	void EquipRightWeapon();
	UFUNCTION(BlueprintCallable)
	void UnEquipRightWeapon();
	UFUNCTION(BlueprintCallable)
	void ShowItem();
	UFUNCTION(BlueprintCallable)
	void HiddenItem();
	UFUNCTION(BlueprintCallable)
	void CaculatePortion();
	void StopCaculatePortion();

	void SpawnWeapon();
	void SpawnItem();

	

	bool GetIsMovementInput() const noexcept { return isMovementInput; }

	inline bool HasMovementKeyInput() const;

private:


	UPROPERTY(VisibleAnywhere, Category = "Yoru|Input")
	TObjectPtr<class UInputAction> moveAction;

	UPROPERTY(VisibleAnywhere, Category = "Yoru|Input")
	TObjectPtr<class UInputAction> lookAction;

	UPROPERTY(VisibleAnywhere, Category = "Yoru|Input")
	TObjectPtr<class UInputAction> jumpAction;

	UPROPERTY(VisibleAnywhere, Category = "Yoru|Input")
	TObjectPtr<class UInputAction> moveChangeAction;

	UPROPERTY(VisibleAnywhere, Category = "Yoru|Input")
	TObjectPtr<class UInputAction> runRollAction;

	UPROPERTY(VisibleAnywhere, Category = "Yoru|Input")
	TObjectPtr<class UInputAction> crouchAction;

	UPROPERTY(VisibleAnywhere, Category = "Yoru|Input")
	TObjectPtr<class UInputAction> changeWeaponAction;

	UPROPERTY(VisibleAnywhere, Category = "Yoru|Input")
	TObjectPtr<class UInputAction> useItemAction;

	UPROPERTY(EditAnywhere, Category = "Yoru|Montage")
	TObjectPtr<UAnimMontage> rollingMontage;

	UPROPERTY(EditAnywhere, Category = "Yoru|Montage")
	TObjectPtr<UAnimMontage> stepBackMontage;

	UPROPERTY(EditAnywhere, Category = "Yoru|Montage")
	TObjectPtr<UAnimMontage> equipMontage;

	UPROPERTY(EditAnywhere, Category = "Yoru|Montage")
	TObjectPtr<UAnimMontage> unEquipMontage;

	UPROPERTY(EditAnywhere, Category = "Yoru|Montage")
	TObjectPtr<UAnimMontage> useItemMontage;

	float elapsedTimePressedMove{};
	float elapsedTimePressedRunOrRolling{};
	float moveSpeed{};
	bool isMovementInput{ true };
	bool isUseRightWeapon{ true };
	bool isHaveRightWeapon{ true };


public:


	UPROPERTY(EditAnywhere, Category = "Yoru|Mouse")
	double mouseSpeed{ 35.0 };

	UPROPERTY(BlueprintReadWrite, Category = "Yoru|Hit")
	bool canBeHit{ true };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Yoru|Item")
	int32 portionCount{ 5 };

	FTimerHandle inputTimeHandle{};
	FTimerHandle equipTimeHandle{};
	FTimerHandle spawnTimeHandle{};
	FTimerHandle HPTimeHandle{};
};
