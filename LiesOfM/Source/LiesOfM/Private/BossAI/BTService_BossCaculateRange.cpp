// Fill out your copyright notice in the Description page of Project Settings.


#include "BossAI/BTService_BossCaculateRange.h"
#include "BossAI/BossAI.h"
#include "AIController.h"
#include "Interface/BossAIInterface.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_BossCaculateRange::UBTService_BossCaculateRange()
{
	NodeName = TEXT("CaculateRange");
	Interval = 0.5f;
}

void UBTService_BossCaculateRange::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* Target = Cast<APawn>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(BBKEY_TARGET));
	if (!Target)
	{
		return;
	}

	APawn* ControllingPawn{ OwnerComp.GetAIOwner()->GetPawn() };
	if (!ControllingPawn)
	{
		return;
	}

	FVector Center{ ControllingPawn->GetActorLocation() };
	UWorld* World{ ControllingPawn->GetWorld() };
	if (!World)
	{
		return;
	}

	IBossAIInterface* AIPawn = Cast<IBossAIInterface>(ControllingPawn);
	if (!AIPawn)
	{
		return;
	}

	float DistanceToTarget = ControllingPawn->GetDistanceTo(Target);
	float RangeWithRaduis = AIPawn->GetAIAttackLongRange();
	if (DistanceToTarget <= RangeWithRaduis)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool(BBKEY_RANGE, true);
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool(BBKEY_RANGE, false);
	}
}
