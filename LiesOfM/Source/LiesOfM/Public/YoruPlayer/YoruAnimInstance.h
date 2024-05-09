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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Yoru|Character")
	class AYoru* owner;
};
