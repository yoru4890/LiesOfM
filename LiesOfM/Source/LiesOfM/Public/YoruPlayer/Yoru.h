// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Yoru.generated.h"

UENUM(BlueprintType)
enum class EPlayerState : uint8
{ 
	NONE UMETA(DisplayName = "NONE"),
	Running UMETA(DisplayName = "Running"),
	Rolling UMETA(DisplayName = "Rolling"),
	StepBack UMETA(DisplayName = "StepBack"),
	Crouch UMETA(DisplayName = "Crouch"),

	SIZE
};


UCLASS()
class LIESOFM_API AYoru : public ACharacter
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

	UPROPERTY(BlueprintReadWrite, Category = "Yoru|Component")
	TObjectPtr<class UYoruMoveComponent> moveComp{};

	UPROPERTY(BlueprintReadWrite, Category = "Yoru|Component")
	TObjectPtr<class UYoruStatComponent> statComp{};

	UPROPERTY(BlueprintReadWrite, Category = "Yoru|Component")
	TObjectPtr<class UYoruWidgetComponent> widgetComp{};

private:
	UPROPERTY(VisibleAnywhere, Category = "Yoru|Input")
	bool isPressedMovementInput{};

	EPlayerState currentPlayerState{ EPlayerState::NONE };
};
