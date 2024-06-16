// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyBaseMovement.h"
#include "Enemy/EnemyBoss.h"
#include "Kismet/GameplayStatics.h"

UEnemyBaseMovement::UEnemyBaseMovement()
{
	PrimaryComponentTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UCurveFloat> BackMoveCurveFinder(TEXT("/Script/Engine.CurveFloat'/Game/AAA/Curves/C_BackMove.C_BackMove'"));

	if (BackMoveCurveFinder.Succeeded())
	{
		BackMoveCurve = BackMoveCurveFinder.Object;
	}
}

void UEnemyBaseMovement::BeginPlay()
{
	Super::BeginPlay();

	Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	InitTimeLine();
}

void UEnemyBaseMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	BackMoveTL.TickTimeline(DeltaTime);
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

void UEnemyBaseMovement::backMoveTick()
{
	
	float timelineValue = BackMoveTL.GetPlaybackPosition();
	float currentValue = BackMoveCurve->GetFloatValue(timelineValue);

	FVector Direction{ Player->GetActorForwardVector().GetSafeNormal2D()};
	
	me->SetActorLocation(me->GetActorLocation() + Direction * currentValue, true);
}

void UEnemyBaseMovement::backMoveEnd()
{
	UE_LOG(LogTemp, Warning, TEXT("Finished"));
}
