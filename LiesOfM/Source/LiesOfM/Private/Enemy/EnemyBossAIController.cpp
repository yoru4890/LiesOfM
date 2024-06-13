// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyBossAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Enemy/EnemyBoss.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BossAI/BossAI.h"

AEnemyBossAIController::AEnemyBossAIController()
{
	ConstructorHelpers::FObjectFinder<UBlackboardData> BBFinder(TEXT("/Script/AIModule.BlackboardData'/Game/AAA/Blueprints/Enemy/Boss/BB_EnemyBoss.BB_EnemyBoss'"));

	if (BBFinder.Object)
	{
		ownedBB = BBFinder.Object;
	}

	ConstructorHelpers::FObjectFinder<UBehaviorTree> BTFinder(TEXT("/Script/AIModule.BehaviorTree'/Game/AAA/Blueprints/Enemy/Boss/BT_EnemyBoss.BT_EnemyBoss'"));

	if (BTFinder.Object)
	{
		ownedBT = BTFinder.Object;
	}
}

void AEnemyBossAIController::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemyBossAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
}

void AEnemyBossAIController::RunAI()
{
	UBlackboardComponent* BlackboardPtr{ Blackboard.Get() };
	if (UseBlackboard(ownedBB, BlackboardPtr))
	{
		Blackboard->SetValueAsObject(BBKEY_TARGET, UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
		bool RunResult = RunBehaviorTree(ownedBT);
		ensure(RunResult);

	}
}

void AEnemyBossAIController::StopAI()
{
	UBehaviorTreeComponent* BTComponent = Cast<UBehaviorTreeComponent>(BrainComponent);
	if (BTComponent)
	{
		BTComponent->StopTree();
	}
}
