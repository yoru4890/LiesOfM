// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "YoruPlayer/YoruBaseComponent.h"
#include "Components/TimeLineComponent.h"
#include "YoruWidgetComponent.generated.h"

UCLASS()
class LIESOFM_API UYoruWidgetComponent : public UYoruBaseComponent
{
	GENERATED_BODY()

public:
	UYoruWidgetComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UPROPERTY(BlueprintReadWrite, Category = "Yoru|widget")
	TSubclassOf<class UUserWidget> widgetClass;

	UPROPERTY(BlueprintReadWrite, Category = "Yoru|widget")
	UUserWidget* widgetCombat;

	UPROPERTY(EditAnywhere, Category = "Yoru|Widget")
	class UProgressBar* staminaBar;

	UPROPERTY(EditAnywhere, Category = "Yoru|Widget")
	class UProgressBar* HPBar;

	UPROPERTY(EditAnywhere, Category = "Yoru|Widget")
	class UTextBlock* PortionCountText;

	UPROPERTY(BlueprintReadWrite, Category = "Yoru|widget")
	TSubclassOf<class UUserWidget> lockonWidgetClass;

	UPROPERTY(EditAnywhere, Category = "Yoru|Timeline")
	UCurveFloat* curve{};

	void InitDelegate();
	void InitWidget();
	void InitTimeline();

	UFUNCTION()
	void StaminaRegenTick();

	UFUNCTION()
	void HPRegenTick();

	UFUNCTION()
	void TempFinish();

	UFUNCTION()
	void StaminaRegenerationToggle(bool isStart);

	UFUNCTION()
	void HPRegenerationToggle(bool isStart);

	UFUNCTION()
	void UpdateStamina();

	UFUNCTION()
	void UpdateHP();

	UFUNCTION()
	void UpdatePortion();

	float timelineValue{};
	FTimeline staminaRegenerationLooper;
	FTimeline HPRegenerationLooper;
};
