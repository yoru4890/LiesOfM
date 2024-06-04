// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyCommonAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Enemy/EnemyCommon.h"
#include "GameFramework/CharacterMovementComponent.h"

AEnemyCommonAIController::AEnemyCommonAIController()
{
}

void AEnemyCommonAIController::BeginPlay()
{
	Super::BeginPlay();

	owner = Cast<AEnemyCommon>(this->GetCharacter());
	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
}

void AEnemyCommonAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (LineOfSightTo(PlayerPawn))
	{
		//SetFocus(PlayerPawn);
		
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
	}
}
