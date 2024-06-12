// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "EnemyBossAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class LIESOFM_API UEnemyBossAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	UEnemyBossAnimInstance();

protected:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Yoru|Character")
	class AEnemyBoss* owner{};

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Yoru|Character")
	class UCharacterMovementComponent* charMoveComp{};
};
