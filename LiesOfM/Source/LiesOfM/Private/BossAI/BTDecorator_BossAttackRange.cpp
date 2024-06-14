// Fill out your copyright notice in the Description page of Project Settings.


#include "BossAI/BTDecorator_BossAttackRange.h"
#include "BossAI/BossAI.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Interface/BossAIInterface.h"
#include "Kismet/GameplayStatics.h"

UBTDecorator_BossAttackRange::UBTDecorator_BossAttackRange()
{
	NodeName = TEXT("CanAttack");
}

bool UBTDecorator_BossAttackRange::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (!ControllingPawn)
	{
		return false;
	}

	IBossAIInterface* AIPawn = Cast<IBossAIInterface>(ControllingPawn);
	if (!AIPawn)
	{
		return false;
	}

	APawn* Target = Cast<APawn>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(BBKEY_TARGET));
	if (!Target)
	{
		return false;
	}

	float DistanceToTarget = ControllingPawn->GetDistanceTo(Target);
	float AttackRangeWithRaduis = AIPawn->GetAIAttackLongRange();
	bResult = (DistanceToTarget <= AttackRangeWithRaduis);
	return bResult;
}
