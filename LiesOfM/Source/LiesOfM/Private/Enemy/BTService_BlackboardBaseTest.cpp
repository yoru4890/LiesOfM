// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/BTService_BlackboardBaseTest.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "Enemy/EnemyCommonAIController.h"

UBTService_BlackboardBaseTest::UBTService_BlackboardBaseTest()
{
	NodeName = "Update Location";
}

void UBTService_BlackboardBaseTest::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn))
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("isFindPlayer"), true);
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("isFindPlayer"), false);
		//GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
	}


	//OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PlayerPawn->GetActorLocation());
}
