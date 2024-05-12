// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "YoruPlayer/YoruBaseComponent.h"
#include "InputActionvalue.h"
#include "YoruMoveComponent.generated.h"

UCLASS()
class LIESOFM_API UYoruMoveComponent : public UYoruBaseComponent
{
	GENERATED_BODY()
	

public:
	UYoruMoveComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	void Move(const FInputActionValue& value);
	void NoMove(const FInputActionValue& value);
	void Look(const FInputActionValue& value);
	void Jump(const FInputActionValue& value);
	void ChangeWalk(const FInputActionValue& value);
	void ChangeJog(const FInputActionValue& value);
	void RunOrRolling(const FInputActionValue& value);
	inline bool HasMovementKeyInput() const;
	void StopRunning();
	void MovementInputHandler(float duration, bool isStopInput);

	void SetMovementInputFalse() { isMovementInput = false; }

private:
	UPROPERTY(VisibleAnywhere, Category ="Yoru|Input")
	TObjectPtr<class UInputMappingContext> defaultInputMappingContext;

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

	float elapsedTimePressedMove{};
	float elapsedTimePressedRunOrRolling{};
	float moveSpeed{};
	bool isMovementInput{ true };

public:
	UPROPERTY(EditAnywhere, Category = "Yoru|Mouse")
	double mouseSpeed{ 35.0 };

	FTimerHandle inputTimeHandle{};
};
