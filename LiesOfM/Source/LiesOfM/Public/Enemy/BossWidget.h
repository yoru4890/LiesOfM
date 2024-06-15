// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy/EnemyBaseComponent.h"
#include "BossWidget.generated.h"

/**
 * 
 */
UCLASS()
class LIESOFM_API UBossWidget : public UEnemyBaseComponent
{
	GENERATED_BODY()
	
public:
	UBossWidget();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void InitWidget();
	void UpdateHP();
	void UpdateNameText();

	void UpdateDamageText(float& damage);
	void HiddenDamageText(float& damage);

	void ShowWidget();
	void HiddenWidget();

public:
	UPROPERTY(BlueprintReadWrite, Category = "Enemy|widget")
	TSubclassOf<class UUserWidget> widgetClass;

	UPROPERTY(BlueprintReadWrite, Category = "Enemy|widget")
	UUserWidget* widgetHP;

	UPROPERTY(EditAnywhere, Category = "Enemy|Widget")
	class UProgressBar* HPBar;

	UPROPERTY(EditAnywhere, Category = "Enemy|Widget")
	class UTextBlock* BossNameText;

	UPROPERTY(EditAnywhere, Category = "Enemy|Widget")
	class UTextBlock* TotalDamageText;

private:
	FTimerHandle damageTextTimeHandle{};

};
