// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_BlackboardBaseTest.generated.h"

/**
 * 
 */
UCLASS()
class LIESOFM_API UBTService_BlackboardBaseTest : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBTService_BlackboardBaseTest();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;


};
