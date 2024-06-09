// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTBCanAttack.generated.h"

/**
 * 
 */
UCLASS()
class LIESOFM_API UBTBCanAttack : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UBTBCanAttack();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
