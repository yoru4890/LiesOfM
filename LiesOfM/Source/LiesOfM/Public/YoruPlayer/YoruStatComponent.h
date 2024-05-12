// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "YoruPlayer/YoruBaseComponent.h"
#include "YoruStatComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FUpdateStaminaDelegate);
DECLARE_MULTICAST_DELEGATE_OneParam(FRegenerateStaminaDelegate, bool);

UCLASS()
class LIESOFM_API UYoruStatComponent : public UYoruBaseComponent
{
	GENERATED_BODY()

public:
	UYoruStatComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	float DecreaseStamina(float amount);

	float GetStaminaRatio();

	inline bool CheckStamina(float staminaNeeded) const noexcept;

	void HandleStaminaRegen(bool isStartRegen, float duration);

	void CallUpdateStamina() { onUpdateStamina.Broadcast(); }
	void CallRegenerateStartStamina() { onRegenerateStamina.Broadcast(true); }
	void CallRegenerateStopStamina() { onRegenerateStamina.Broadcast(false); }

	void RunTick();

	UFUNCTION()
	void CaculateStaminaRegen();

public:
	FUpdateStaminaDelegate onUpdateStamina;
	FRegenerateStaminaDelegate onRegenerateStamina;

	UPROPERTY(BlueprintReadWrite, Category = "Your|Stamina")
	float currentStamina{ 60.0f };

	UPROPERTY(BlueprintReadWrite, Category = "Your|Stamina")
	float maxStamina{ 60.0f };

	UPROPERTY(BlueprintReadWrite, Category = "Your|Stamina")
	float StaminaRegen{ 0.2f };

	UPROPERTY(BlueprintReadWrite, Category = "Yoru|Speed")
	float walkSpeed{ 150.0f };

	UPROPERTY(BlueprintReadWrite, Category = "Your|Speed")
	float jogSpeed{ 350.0f };

	UPROPERTY(BlueprintReadWrite, Category = "Yoru|Speed")
	float runSpeed{ 600.0f };

	FTimerHandle handleStamina{};
};
