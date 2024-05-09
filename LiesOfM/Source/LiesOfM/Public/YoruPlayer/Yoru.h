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

private:
	UPROPERTY(VisibleAnywhere, Category = "Yoru|Compoent")
	TObjectPtr<class USpringArmComponent> mainSpringArmComp{};

	UPROPERTY(VisibleAnywhere, Category = "Yoru|Compoent")
	TObjectPtr<class UCameraComponent> mainCamera{};

	UPROPERTY(VisibleAnywhere, Category = "Yoru|Component")
	TObjectPtr<class UYoruMoveComponent> moveComp{};

	UPROPERTY(VisibleAnywhere, Category = "Yoru|Component")
	TObjectPtr<class UYoruStatComponent> statComp{};

public:
	TObjectPtr<class UYoruStatComponent> GetStatComp() const noexcept { return statComp; }
};
