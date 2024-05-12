// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Yoru.generated.h"

UCLASS()
class LIESOFM_API AYoru : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AYoru();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	inline TObjectPtr<class UYoruStatComponent> GetStatComp() const noexcept { return statComp; }

	UFUNCTION(BlueprintCallable)
	inline bool GetisPressedMovementInput() const noexcept { return isPressedMovementInput; }
	UFUNCTION(BlueprintCallable)
	inline void SetisPressedMovementInput(bool isPressed) { isPressedMovementInput = isPressed; }

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
};
