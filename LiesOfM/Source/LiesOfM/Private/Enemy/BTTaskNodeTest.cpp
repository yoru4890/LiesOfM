// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/BTTaskNodeTest.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "AIController.h"
#include "Enemy/EnemyCommon.h"
//#include "Engine/GameEngine.h"

UBTTaskNodeTest::UBTTaskNodeTest()
{
	NodeName = "Test";
}

EBTNodeResult::Type UBTTaskNodeTest::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AEnemyCommon* enemyCommon = Cast<AEnemyCommon>(OwnerComp.GetAIOwner()->GetCharacter());

	if (!enemyCommon)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Task Failed"));
		return EBTNodeResult::Failed;
	}

	enemyCommon->CommonAttack();

	return EBTNodeResult::Succeeded;
}
