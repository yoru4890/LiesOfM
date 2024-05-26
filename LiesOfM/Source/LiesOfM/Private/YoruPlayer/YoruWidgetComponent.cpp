// Fill out your copyright notice in the Description page of Project Settings.


#include "YoruPlayer/YoruWidgetComponent.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "YoruPlayer/Yoru.h"
#include "YoruPlayer/YoruStatComponent.h"
#include "Components/WidgetComponent.h"

UYoruWidgetComponent::UYoruWidgetComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	static ConstructorHelpers::FClassFinder<UUserWidget> widgetFinder(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/AAA/Widget/WB_YoruCombat.WB_YoruCombat_C'"));

	if (widgetFinder.Succeeded())
	{
		widgetClass = widgetFinder.Class;
	}

	static ConstructorHelpers::FClassFinder<UUserWidget> lockonWidgetFinder(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/AAA/Widget/WB_Lockon.WB_Lockon_C'"));

	if (lockonWidgetFinder.Succeeded())
	{
		lockonWidgetClass = lockonWidgetFinder.Class;
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
	
	InitWidget();
	InitTimeline();
	InitDelegate();
}

void UYoruWidgetComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	staminaRegenerationLooper.TickTimeline(DeltaTime);
}

void UYoruWidgetComponent::InitDelegate()
{
	me->statComp->onUpdateStamina.AddUObject(this, &UYoruWidgetComponent::UpdateStamina);
	me->statComp->onRegenerateStamina.AddUObject(this, &UYoruWidgetComponent::staminaRegenerationToggle);
	me->statComp->onUpdateHP.AddUObject(this, &UYoruWidgetComponent::UpdateHP);
}

void UYoruWidgetComponent::InitWidget()
{
	if (widgetClass)
	{
		widgetCombat = CreateWidget(GetWorld()->GetFirstPlayerController(), widgetClass);
		widgetCombat->AddToViewport();
		staminaBar = Cast<UProgressBar>(widgetCombat->GetWidgetFromName("StaminaBar"));
		HPBar = Cast<UProgressBar>(widgetCombat->GetWidgetFromName("HPBar"));
		UpdateStamina();
		UpdateHP();

		me->lockonWidget->SetWidgetClass(lockonWidgetClass);
	}
	else
	{
		
	}
}

void UYoruWidgetComponent::InitTimeline()
{
	if (curve)
	{
		FOnTimelineFloat TimelineCallback;
		FOnTimelineEventStatic TimelineFinishedCallback;

		TimelineCallback.BindUFunction(this, FName("StaminaRegenTick"));
		TimelineFinishedCallback.BindUFunction(this, FName{ TEXT("TempFinish") });
		staminaRegenerationLooper.AddInterpFloat(curve, TimelineCallback);
		staminaRegenerationLooper.SetTimelineFinishedFunc(TimelineFinishedCallback);
		staminaRegenerationLooper.SetLooping(true);
	}
}

void UYoruWidgetComponent::StaminaRegenTick()
{
	/*timelineValue = staminaRegenerationLooper.GetPlaybackPosition();
	float currentValue = curve->GetFloatValue(timelineValue);*/

	me->statComp->CaculateStaminaRegen();
}

void UYoruWidgetComponent::TempFinish()
{
	UE_LOG(LogTemp, Warning, TEXT("Finished"));
}

void UYoruWidgetComponent::staminaRegenerationToggle(bool isStart)
{
	if (isStart)
	{

		staminaRegenerationLooper.PlayFromStart();
	}
	else
	{
		staminaRegenerationLooper.Stop();
	}
}

void UYoruWidgetComponent::UpdateStamina()
{
	staminaBar->SetPercent(me->statComp->GetStaminaRatio());
}

void UYoruWidgetComponent::UpdateHP()
{
	HPBar->SetPercent(me->statComp->GetHPRatio());
}
