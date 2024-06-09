// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTaskNodeTest.generated.h"

UCLASS()
class LIESOFM_API UBTTaskNodeTest : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTTaskNodeTest();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
