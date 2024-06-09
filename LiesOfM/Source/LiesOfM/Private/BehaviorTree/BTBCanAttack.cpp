// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/BTBCanAttack.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Pawn.h"
#include "AIController.h"
#include "Enemy/EnemyCommon.h"

UBTBCanAttack::UBTBCanAttack()
{
	NodeName = "CanAttack";
}

EBTNodeResult::Type UBTBCanAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (!PlayerPawn)
	{
		return EBTNodeResult::Failed;
	}

	AEnemyCommon* enemyCommon = Cast<AEnemyCommon>(OwnerComp.GetAIOwner()->GetPawn());
	if (!enemyCommon)
	{
		return EBTNodeResult::Failed;
	}

	double distance = FVector::Distance(PlayerPawn->GetActorLocation(), enemyCommon->GetActorLocation());

	if (distance <= enemyCommon->attackRange)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("isInRange"), true);
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("isInRange"), false);
	}

	return EBTNodeResult::Succeeded;
}
