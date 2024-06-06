// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyCommonAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Enemy/EnemyCommon.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

AEnemyCommonAIController::AEnemyCommonAIController()
{
	ConstructorHelpers::FObjectFinder<UBehaviorTree> BTFinder(TEXT("/Script/AIModule.BehaviorTree'/Game/AAA/Blueprints/Enemy/BT_EnemyCommon.BT_EnemyCommon'"));

	if (BTFinder.Succeeded())
	{
		ownedBT = BTFinder.Object;
	}
}

void AEnemyCommonAIController::BeginPlay()
{
	Super::BeginPlay();

	owner = Cast<AEnemyCommon>(this->GetCharacter());
	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (ownedBT)
	{
		if (!RunBehaviorTree(ownedBT))
		{
			UE_LOG(LogTemp, Warning, TEXT("f"));
		}

		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
		GetBlackboardComponent()->SetValueAsVector(TEXT("DefaultLocation"), owner->GetActorLocation());
		GetBlackboardComponent()->SetValueAsVector(TEXT("PatrolLocation0"), PatrolLocation[0] + owner->GetActorLocation().Z);
		GetBlackboardComponent()->SetValueAsVector(TEXT("PatrolLocation1"), PatrolLocation[1] + owner->GetActorLocation().Z);
	}

}

void AEnemyCommonAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	//if (LineOfSightTo(PlayerPawn))
	//{
	//	GetBlackboardComponent()->SetValueAsBool(TEXT("isFindPlayer"), true);
	//	GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
	//}
	//else
	//{
	//	GetBlackboardComponent()->SetValueAsBool(TEXT("isFindPlayer"), false);
	//	//GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
	//}

	/*if (LineOfSightTo(PlayerPawn))
	{
		SetFocus(PlayerPawn);
		
		double distance{ FVector::Distance(owner->GetActorLocation(), PlayerPawn->GetActorLocation()) };
		
		if (distance > 200)
		{
			MoveToActor(PlayerPawn, 100);
		}
		else
		{
			if (owner)
			{
				if (!(owner->GetMesh()->GetAnimInstance()->IsAnyMontagePlaying()))
				{
					owner->GetMesh()->GetAnimInstance()->Montage_Play(owner->attackMontage);
				}
			}
		}
	}
	else
	{
		ClearFocus(EAIFocusPriority::Gameplay);
		StopMovement();
	}*/
}
