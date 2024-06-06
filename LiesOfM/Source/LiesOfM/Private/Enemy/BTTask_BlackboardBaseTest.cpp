// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/BTTask_BlackboardBaseTest.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_BlackboardBaseTest::UBTTask_BlackboardBaseTest()
{
	NodeName = "Clear Blackboard Value";
}

EBTNodeResult::Type UBTTask_BlackboardBaseTest::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());

	return EBTNodeResult::Succeeded;
}
