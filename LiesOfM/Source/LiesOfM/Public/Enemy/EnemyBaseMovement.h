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

	UFUNCTION()
	void JumpMoveTick();

	UFUNCTION()
	void JumpMoveEnd();

	UFUNCTION(BlueprintCallable)
	void JumpMoveToggle(bool isStart);

	UPROPERTY(EditAnywhere)
	UCurveVector* JumpMoveCurve{};

	UFUNCTION()
	void ChaseMoveTick();

	UFUNCTION()
	void ChaseMoveEnd();

	UFUNCTION(BlueprintCallable)
	void ChaseMoveToggle(bool isStart);

	UPROPERTY(EditAnywhere)
	UCurveFloat* ChaseMoveCurve{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float JumpSpeed{ 3.0f };

	void SetSubBackMoveValue(float value) { subBackMoveValue = value; }
private:
	
	class APawn* Player{};
	FTimeline BackMoveTL{};
	FTimeline JumpMoveTL{};
	FTimeline ChaseMoveTL{};

	float subBackMoveValue{1};

	FVector StartPos{};
	FVector PlayerPos{};
	FVector TargetPos{};
	bool isMiddle{};
};
