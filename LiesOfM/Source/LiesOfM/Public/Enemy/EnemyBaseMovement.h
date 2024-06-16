// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy/EnemyBaseComponent.h"
#include "Components/TimeLineComponent.h"
#include "EnemyBaseMovement.generated.h"

/**
 * 
 */
UCLASS()
class LIESOFM_API UEnemyBaseMovement : public UEnemyBaseComponent
{
	GENERATED_BODY()
public:
	UEnemyBaseMovement();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void InitTimeLine();

	UFUNCTION()
	void backMoveTick();

	UFUNCTION()
	void backMoveEnd();

	UFUNCTION(BlueprintCallable)
	void GrabAttackedMoveToggle(bool isStart);

	UPROPERTY(EditAnywhere)
	UCurveFloat* BackMoveCurve{};
private:
	
	class APawn* Player{};
	FTimeline BackMoveTL{};
};
