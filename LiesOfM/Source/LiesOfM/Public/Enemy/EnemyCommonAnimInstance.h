// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "EnemyCommonAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class LIESOFM_API UEnemyCommonAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UEnemyCommonAnimInstance();

protected:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Yoru|Character")
	class AEnemyCommon* owner{};

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Yoru|Character")
	class UCharacterMovementComponent* charMoveComp{};
};
