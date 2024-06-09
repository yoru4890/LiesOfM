// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyCommonAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Enemy/EnemyCommon.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/ABAI.h"

AEnemyCommonAIController::AEnemyCommonAIController()
{
	ConstructorHelpers::FObjectFinder<UBlackboardData> BBFinder(TEXT("/Script/AIModule.BlackboardData'/Game/AAA/Blueprints/Enemy/BB_EnemyCommon.BB_EnemyCommon'"));

	if (BBFinder.Object)
	{
		ownedBB = BBFinder.Object;
	}

	ConstructorHelpers::FObjectFinder<UBehaviorTree> BTFinder(TEXT("/Script/AIModule.BehaviorTree'/Game/AAA/Blueprints/Enemy/BT_EnemyCommon.BT_EnemyCommon'"));

	if (BTFinder.Object)
	{
		ownedBT = BTFinder.Object;
	}
}

void AEnemyCommonAIController::BeginPlay()
{
	Super::BeginPlay();

}

void AEnemyCommonAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	RunAI();
}

void AEnemyCommonAIController::RunAI()
{
	UBlackboardComponent* BlackboardPtr{ Blackboard.Get() };
	if (UseBlackboard(ownedBB, BlackboardPtr))
	{
		Blackboard->SetValueAsVector(BBKEY_HOMEPOS, GetPawn()->GetActorLocation());
		bool RunResult = RunBehaviorTree(ownedBT);
		ensure(RunResult);
	}
}

void AEnemyCommonAIController::StopAI()
{
	UBehaviorTreeComponent* BTComponent = Cast<UBehaviorTreeComponent>(BrainComponent);
	if (BTComponent)
	{
		BTComponent->StopTree();
	}
}
