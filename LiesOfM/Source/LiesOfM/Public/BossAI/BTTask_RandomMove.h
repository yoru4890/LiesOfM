// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_RandomMove.generated.h"

/**
 * 
 */
UCLASS()
class LIESOFM_API UBTTask_RandomMove : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UBTTask_RandomMove();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
