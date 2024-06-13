// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_BossCaculateRange.generated.h"

/**
 * 
 */
UCLASS()
class LIESOFM_API UBTService_BossCaculateRange : public UBTService
{
	GENERATED_BODY()
public:
	UBTService_BossCaculateRange();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

private:
	float elapsedTime{};
};
