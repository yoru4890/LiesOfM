// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyBaseMovement.h"
#include "Enemy/EnemyBoss.h"
#include "Kismet/GameplayStatics.h"
#include "Curves/CurveVector.h"
#include "Enemy/EnemyBossAIController.h"
#include "GameFramework/CharacterMovementComponent.h"

UEnemyBaseMovement::UEnemyBaseMovement()
{
	PrimaryComponentTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UCurveFloat> BackMoveCurveFinder(TEXT("/Script/Engine.CurveFloat'/Game/AAA/Curves/C_BackMove.C_BackMove'"));

	if (BackMoveCurveFinder.Succeeded())
	{
		BackMoveCurve = BackMoveCurveFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UCurveVector> JumpMoveCurveFinder(TEXT("/Script/Engine.CurveVector'/Game/AAA/Curves/C_JumpMove.C_JumpMove'"));

	if (JumpMoveCurveFinder.Succeeded())
	{
		JumpMoveCurve = JumpMoveCurveFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UCurveFloat> ChaseMoveCurveFinder(TEXT("/Script/Engine.CurveFloat'/Game/AAA/Curves/C_ChaseMove.C_ChaseMove'"));

	if (ChaseMoveCurveFinder.Succeeded())
	{
		ChaseMoveCurve = ChaseMoveCurveFinder.Object;
	}
}

void UEnemyBaseMovement::BeginPlay()
{
	Super::BeginPlay();

	Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	realMe = Cast<AEnemyBoss>(me);

	InitTimeLine();
}

void UEnemyBaseMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	BackMoveTL.TickTimeline(DeltaTime);
	JumpMoveTL.TickTimeline(DeltaTime);
	ChaseMoveTL.TickTimeline(DeltaTime);
}

void UEnemyBaseMovement::InitTimeLine()
{
	if (BackMoveCurve)
	{
		FOnTimelineFloat TimelineCallback;
		FOnTimelineEventStatic TimelineFinishedCallback;

		TimelineCallback.BindUFunction(this, FName("backMoveTick"));
		TimelineFinishedCallback.BindUFunction(this, FName{ TEXT("backMoveEnd") });
		BackMoveTL.AddInterpFloat(BackMoveCurve, TimelineCallback);
		BackMoveTL.SetTimelineFinishedFunc(TimelineFinishedCallback);
		BackMoveTL.SetLooping(false);
	}

	if (JumpMoveCurve)
	{
		FOnTimelineVector TimelineCallback;
		FOnTimelineEventStatic TimelineFinishedCallback;

		TimelineCallback.BindUFunction(this, FName("JumpMoveTick"));
		TimelineFinishedCallback.BindUFunction(this, FName{ TEXT("JumpMoveEnd") });
		JumpMoveTL.AddInterpVector(JumpMoveCurve, TimelineCallback);
		JumpMoveTL.SetTimelineFinishedFunc(TimelineFinishedCallback);
		JumpMoveTL.SetLooping(false);
	}

	if (ChaseMoveCurve)
	{
		FOnTimelineFloat TimelineCallback;
		FOnTimelineEventStatic TimelineFinishedCallback;

		TimelineCallback.BindUFunction(this, FName("ChaseMoveTick"));
		TimelineFinishedCallback.BindUFunction(this, FName{ TEXT("ChaseMoveEnd") });
		ChaseMoveTL.AddInterpFloat(ChaseMoveCurve, TimelineCallback);
		ChaseMoveTL.SetTimelineFinishedFunc(TimelineFinishedCallback);
		ChaseMoveTL.SetLooping(false);
	}
}

void UEnemyBaseMovement::GrabAttackedMoveToggle(bool isStart)
{

	if (isStart)
	{
		BackMoveTL.PlayFromStart();
	}
	else
	{
		BackMoveTL.Stop();
	}
}

void UEnemyBaseMovement::JumpMoveTick()
{
	float timelineValue = JumpMoveTL.GetPlaybackPosition();
	FVector currentValue = JumpMoveCurve->GetVectorValue(timelineValue);

	if (!isMiddle && timelineValue >= 0.4)
	{
		isMiddle = true;
		PlayerPos = Player->GetActorLocation();
		TargetPos = (StartPos - PlayerPos);
		TargetPos = (TargetPos / TargetPos.Length())* 200.0 + PlayerPos;
		TargetPos.Z = 0;
	}

	FVector tempLoc = me->GetActorLocation();
	tempLoc.Z = 0;
	FVector tempDest = FMath::VInterpTo(tempLoc, TargetPos, GetWorld()->GetDeltaSeconds(), JumpSpeed);
	tempDest.Z = StartPos.Z + currentValue.Z;
	me->SetActorLocation(tempDest, true);
}

void UEnemyBaseMovement::JumpMoveEnd()
{
	UE_LOG(LogTemp, Warning, TEXT("Finished"));
}

void UEnemyBaseMovement::JumpMoveToggle(bool isStart)
{
	if (isStart)
	{
		StartPos = me->GetActorLocation();
		PlayerPos = Player->GetActorLocation();
		TargetPos = (StartPos - PlayerPos);
		TargetPos = (TargetPos / TargetPos.Length()) * 200.0 + PlayerPos;
		TargetPos.Z = 0;
		isMiddle = false;
		JumpMoveTL.PlayFromStart();
	}
	else
	{
		JumpMoveTL.Stop();
	}
}

void UEnemyBaseMovement::ChaseMoveTick()
{
	float timelineValue = ChaseMoveTL.GetPlaybackPosition();
	float currentValue = ChaseMoveCurve->GetFloatValue(timelineValue);

	FVector Direction{Player->GetActorLocation() - realMe->GetActorLocation()};
	Direction.Normalize();
	Direction.Z = 0;

	realMe->BossAIController->MoveToLocation(realMe->GetActorLocation() + Direction * 300.0f);
}

void UEnemyBaseMovement::ChaseMoveEnd()
{
	UE_LOG(LogTemp, Warning, TEXT("Finished"));
	realMe->HiddenYellowMode();
}

void UEnemyBaseMovement::ChaseMoveToggle(bool isStart)
{
	if (realMe->phase == 1)
	{
		if (isStart)
		{
			ChaseMoveTL.PlayFromStart();
			realMe->ShowYellowMode();
			realMe->GetCharacterMovement()->MaxWalkSpeed = 800.0f;
		}
		else
		{
			ChaseMoveTL.Stop();
		}
	}
}

void UEnemyBaseMovement::backMoveTick()
{
	
	float timelineValue = BackMoveTL.GetPlaybackPosition();
	float currentValue = BackMoveCurve->GetFloatValue(timelineValue);

	FVector Direction{ Player->GetActorForwardVector().GetSafeNormal2D()};
	
	me->SetActorLocation(me->GetActorLocation() + Direction * currentValue * subBackMoveValue, true);
}

void UEnemyBaseMovement::backMoveEnd()
{
	UE_LOG(LogTemp, Warning, TEXT("Finished"));
}
