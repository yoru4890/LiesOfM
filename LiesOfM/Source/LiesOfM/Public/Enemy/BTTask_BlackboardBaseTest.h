// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_BlackboardBaseTest.generated.h"

/**
 * 
 */
UCLASS()
class LIESOFM_API UBTTask_BlackboardBaseTest : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBTTask_BlackboardBaseTest();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
