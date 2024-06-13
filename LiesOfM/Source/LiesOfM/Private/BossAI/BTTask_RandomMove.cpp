// Fill out your copyright notice in the Description page of Project Settings.


#include "BossAI/BTTask_RandomMove.h"
#include "BossAI/BossAI.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Interface/BossAIInterface.h"

UBTTask_RandomMove::UBTTask_RandomMove()
{
	NodeName = TEXT("RandomMove");
}

EBTNodeResult::Type UBTTask_RandomMove::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	APawn* ControllingPawn = Cast<APawn>(OwnerComp.GetAIOwner()->GetPawn());
	if (!ControllingPawn)
	{
		return EBTNodeResult::Failed;
	}

	APawn* TargetPawn = Cast<APawn>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(BBKEY_TARGET));
	if (!TargetPawn)
	{
		return EBTNodeResult::Failed;
	}

	IBossAIInterface* AIPawn = Cast<IBossAIInterface>(ControllingPawn);
	if (!AIPawn)
	{
		return EBTNodeResult::Failed;
	}

	FAIRandomMoveFinished OnRandomMoveFinished;
	OnRandomMoveFinished.BindLambda(
		[&]()
		{
			FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		}
	);

	AIPawn->SetAIMoveFinishedDelegate(OnRandomMoveFinished);
	AIPawn->RandomMoveByAI();

	return EBTNodeResult::InProgress;
}
