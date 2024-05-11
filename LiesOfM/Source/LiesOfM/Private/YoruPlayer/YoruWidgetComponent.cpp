// Fill out your copyright notice in the Description page of Project Settings.


#include "YoruPlayer/YoruWidgetComponent.h"
#include "Blueprint/UserWidget.h"

UYoruWidgetComponent::UYoruWidgetComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	static ConstructorHelpers::FClassFinder<UUserWidget> widgetFinder(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/AAA/Widget/WB_YoruCombat.WB_YoruCombat_C'"));

	if (widgetFinder.Succeeded())
	{
		widgetClass = widgetFinder.Class;
	}

	static ConstructorHelpers::FObjectFinder<UCurveFloat> curveFinder(TEXT("/Script/Engine.CurveFloat'/Game/AAA/Curves/C_Temp.C_Temp'"));

	if (curveFinder.Succeeded())
	{
		curve = curveFinder.Object;
	}
}

void UYoruWidgetComponent::BeginPlay()
{
	Super::BeginPlay();
	if (widgetClass)
	{
		widgetCombat = CreateWidget(GetWorld()->GetFirstPlayerController(), widgetClass);
		widgetCombat->AddToViewport();
	}
	else
	{
		return;
	}

	if (curve)
	{
		FOnTimelineFloat TimelineCallback;
		FOnTimelineEventStatic TimelineFinishedCallback;

		TimelineCallback.BindUFunction(this, FName("TempUpdate"));
		TimelineFinishedCallback.BindUFunction(this, FName{ TEXT("TempFinish") });
		myTimeline.AddInterpFloat(curve, TimelineCallback);
		myTimeline.SetTimelineFinishedFunc(TimelineFinishedCallback);
	}

}

void UYoruWidgetComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	myTimeline.TickTimeline(DeltaTime);
}

void UYoruWidgetComponent::TempUpdate()
{
	timelineValue = myTimeline.GetPlaybackPosition();
	float currentValue = curve->GetFloatValue(timelineValue);
	UE_LOG(LogTemp, Warning, TEXT("%f"), currentValue);
}

void UYoruWidgetComponent::TempFinish()
{
	UE_LOG(LogTemp, Warning, TEXT("Finished"));
}

void UYoruWidgetComponent::TempToggle()
{
	myTimeline.PlayFromStart();
}
