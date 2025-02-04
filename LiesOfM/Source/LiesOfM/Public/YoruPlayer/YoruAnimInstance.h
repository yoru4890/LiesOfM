// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "YoruAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class LIESOFM_API UYoruAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UYoruAnimInstance();

protected:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Yoru|Character")
	class AYoru* owner{};

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Yoru|Character")
	class UCharacterMovementComponent* charMoveComp{};

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Yoru|Character")
	FVector velocity{};

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Yoru|Character")
	float moveSpeed{};

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Yoru|Character")
	bool isFalling{};

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Yoru|Character")
	bool isPressedMovementInput{};

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Yoru|Character")
	bool isSkipWalkStart{};

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Yoru|Character")
	bool isFootUp{};

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Yoru|Character")
	bool isWalking{};

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Yoru|Character")
	bool isCrouch{};

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Yoru|Character")
	int useWeaponState{};

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Yoru|Character")
	bool isLockon{};

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Yoru|Character")
	float angle{};
};
