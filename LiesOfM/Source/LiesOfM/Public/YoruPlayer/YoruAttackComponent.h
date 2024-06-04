// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "YoruPlayer/YoruBaseComponent.h"
#include "InputActionvalue.h"
#include "Components/TimeLineComponent.h"
#include "YoruAttackComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class LIESOFM_API UYoruAttackComponent : public UYoruBaseComponent
{
	GENERATED_BODY()
	
public:
	UYoruAttackComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void SetupPlayerInputComponent(class UEnhancedInputComponent* enhancedInputComponent) override;

public:
	void AttackCounterHandler();
	void ResetAttackCounter() { attackCounter = 0; }
	void Attack();
	void HandleAttack();
	void UpdateAttackRotation();
	UAnimMontage* GetCorrectAttackAnimation();
	UAnimMontage* CheckIfCounterExceedsAttack(const TArray<UAnimMontage*>& animations);

	UFUNCTION()
	void RotateAttackDirection();

	UFUNCTION(BlueprintCallable)
	void TriggerLineTrace();

	UFUNCTION(BlueprintCallable)
	void ApplyLineTrace();

	UFUNCTION(BlueprintCallable)
	void StopLineTrace();

	float CaculateDamage();

public:
	UPROPERTY(EditAnywhere, Category = "Yoru|Timeline")
	UCurveFloat* curve{};

	FTimeline attackDirectionTimeLine{};

private:
	UPROPERTY(VisibleAnywhere, Category = "Yoru|Input")
	TObjectPtr<class UInputAction> lightAttackAction;

	int attackCounter{};
	double attackDirectionYaw{};
	double startYaw{};
	double deltaYaw{};

	FTimerHandle attackTimeHandle{};
	FTimerHandle lineTraceTimeHandle{};

	UPROPERTY(VisibleAnywhere, Category = "Yoru|Actor")
	TArray<AActor*> hitActors{};

	UPROPERTY(EditAnywhere, Category = "Yoru|Montage")
	TObjectPtr<UAnimMontage> wallHitMontage;
};
