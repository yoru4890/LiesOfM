// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyCommonAIController.generated.h"

/**
 * 
 */
UCLASS()
class LIESOFM_API AEnemyCommonAIController : public AAIController
{
	GENERATED_BODY()

public:
	AEnemyCommonAIController();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaSeconds) override;

private:
	class APawn* PlayerPawn{};
	class AEnemyCommon* owner{};
};
