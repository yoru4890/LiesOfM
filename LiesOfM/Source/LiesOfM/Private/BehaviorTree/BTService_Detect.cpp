// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/BTService_Detect.h"
#include "BehaviorTree/ABAI.h"
#include "AIController.h"
#include "Interface/CommonAIInterface.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Collision/CollisionChannel.h"

UBTService_Detect::UBTService_Detect()
{
	NodeName = TEXT("Detect");
	Interval = 1.0f;
}

void UBTService_Detect::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	UObject* Target = OwnerComp.GetBlackboardComponent()->GetValueAsObject(BBKEY_TARGET);
	if (Target) { return; }

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

	FCommonAIBeingAttacked OnBeingAttacked;
	OnBeingAttacked.BindLambda(
		[&]()
		{
			OwnerComp.GetBlackboardComponent()->SetValueAsObject(BBKEY_TARGET, UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
		}
	);

	AIPawn->SetAIAttackDelegate(OnBeingAttacked);

	float DetectRadius{ AIPawn->GetAIDetectRange() };

	TArray<FOverlapResult> OverlapResults;
	FCollisionQueryParams CollisionQueryParam(SCENE_QUERY_STAT(Detect), false, ControllingPawn);
	bool bResult = World->OverlapMultiByChannel(
		OverlapResults,
		Center,
		FQuat::Identity,
		CCHANNEL_ENEMYDETECT,
		FCollisionShape::MakeSphere(DetectRadius),
		CollisionQueryParam
	);

	if (bResult)
	{
		for (auto const& OverlapResult : OverlapResults)
		{
			APawn* Pawn = Cast<APawn>(OverlapResult.GetActor());
			if (Pawn && Pawn->GetController()->IsPlayerController())
			{
				FVector actorDirection{ ControllingPawn->GetActorRotation().Vector().GetSafeNormal2D() };
				FVector actorRightDirection{ (FRotationMatrix(ControllingPawn->GetActorRotation()).GetScaledAxis(EAxis::Y)).GetSafeNormal2D() };
				FVector hitDirection{ (Pawn->GetActorLocation() - ControllingPawn->GetActorLocation()).GetSafeNormal2D()};
				double rightDotResult{ FVector::DotProduct(actorRightDirection, hitDirection) };
				double angle{ FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(actorDirection, hitDirection))) };
				if (rightDotResult < 0)
				{
					angle *= -1;
				}

				if (angle >= -45.0f && angle <= 45.0f)
				{
					OwnerComp.GetBlackboardComponent()->SetValueAsObject(BBKEY_TARGET, Pawn);
					return;
				}
			}
		}
	}

	OwnerComp.GetBlackboardComponent()->SetValueAsObject(BBKEY_TARGET, nullptr);
}
