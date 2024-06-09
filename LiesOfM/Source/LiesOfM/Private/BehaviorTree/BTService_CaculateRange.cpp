// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/BTService_CaculateRange.h"
#include "BehaviorTree/ABAI.h"
#include "AIController.h"
#include "Interface/CommonAIInterface.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_CaculateRange::UBTService_CaculateRange()
{
	NodeName = TEXT("CaculateRange");
	Interval = 0.5f;
}

void UBTService_CaculateRange::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
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

	ICommonAIInterface* AIPawn = Cast<ICommonAIInterface>(ControllingPawn);
	if (!AIPawn)
	{
		return;
	}

	float DistanceToTarget = ControllingPawn->GetDistanceTo(Target);
	float RangeWithRaduis = AIPawn->GetAIRange();
	if (DistanceToTarget <= RangeWithRaduis)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool(BBKEY_RANGE, true);
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool(BBKEY_RANGE, false);
	}
}
