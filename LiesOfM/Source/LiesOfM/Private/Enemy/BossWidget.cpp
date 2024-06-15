// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/BossWidget.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Enemy/EnemyBoss.h"
#include "Components/WidgetComponent.h"
#include "Components/TextBlock.h"

UBossWidget::UBossWidget()
{
	PrimaryComponentTick.bCanEverTick = true;

	static ConstructorHelpers::FClassFinder<UUserWidget> widgetFinder(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/AAA/Widget/WB_EnemyBossHP.WB_EnemyBossHP_C'"));

	if (widgetFinder.Succeeded())
	{
		widgetClass = widgetFinder.Class;
	}


}

void UBossWidget::BeginPlay()
{
	Super::BeginPlay();

	InitWidget();
}

void UBossWidget::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UBossWidget::InitWidget()
{
	if (widgetClass)
	{
		widgetHP = CreateWidget(GetWorld()->GetFirstPlayerController(), widgetClass);
		HPBar = Cast<UProgressBar>(widgetHP->GetWidgetFromName("HPBar"));
		BossNameText = Cast<UTextBlock>(widgetHP->GetWidgetFromName("BossName"));
		TotalDamageText = Cast<UTextBlock>(widgetHP->GetWidgetFromName("DamageText"));
		TotalDamageText->SetVisibility(ESlateVisibility::Hidden);

		UpdateHP();
		UpdateNameText();

	}
	else
	{
	}
}

void UBossWidget::UpdateHP()
{
	HPBar->SetPercent(me->GetHPRatio());
}

void UBossWidget::UpdateNameText()
{
	BossNameText->SetText(FText::FromString("Muriel"));
}

void UBossWidget::UpdateDamageText(float& damage)
{
	TotalDamageText->SetText(FText::AsNumber(damage));
	TotalDamageText->SetVisibility(ESlateVisibility::Visible);
	GetWorld()->GetTimerManager().SetTimer(damageTextTimeHandle, [this, &damage]() { HiddenDamageText(damage); }, 0.01f, false, 2.0f);
}

void UBossWidget::HiddenDamageText(float& damage)
{
	damage = 0;
	TotalDamageText->SetVisibility(ESlateVisibility::Hidden);
}

void UBossWidget::ShowWidget()
{
	UpdateHP();
	widgetHP->AddToViewport();
}

void UBossWidget::HiddenWidget()
{
	widgetHP->RemoveFromParent();
}
