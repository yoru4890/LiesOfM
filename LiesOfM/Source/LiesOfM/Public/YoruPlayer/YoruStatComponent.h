// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "YoruPlayer/YoruBaseComponent.h"
#include "YoruStatComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FUpdateStaminaDelegate);
DECLARE_MULTICAST_DELEGATE_OneParam(FRegenerateStaminaDelegate, bool);
DECLARE_MULTICAST_DELEGATE(FUpdateHPDelegate);
DECLARE_MULTICAST_DELEGATE_OneParam(FRegenerateHPDelegate, bool);

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
	float DecreaseHP(float amount);

	float GetStaminaRatio();
	float GetHPRatio();

	inline bool CheckStamina(float staminaNeeded) const noexcept;

	void HandleStaminaRegen(bool isStartRegen, float duration = 0.0f);

	void CallUpdateStamina() { onUpdateStamina.Broadcast(); }
	void CallRegenerateStartStamina() { onRegenerateStamina.Broadcast(true); }
	void CallRegenerateStopStamina() { onRegenerateStamina.Broadcast(false); }

	void HandleHPRegen(bool isStartRegen, float duration = 0.0f);

	void CallUpdateHP() { onUpdateHP.Broadcast(); }
	void CallRegenerateStartHP() { onRegenerateHP.Broadcast(true); }
	void CallRegenerateStopHP() { onRegenerateHP.Broadcast(false); }

	void RunTick();

	UFUNCTION()
	void CaculateStaminaRegen();

	UFUNCTION()
	void CaculateHPRegen();

	UFUNCTION(BlueprintCallable)
	void TempUpdateHP() { onUpdateHP.Broadcast(); }



public:
	FUpdateStaminaDelegate onUpdateStamina;
	FRegenerateStaminaDelegate onRegenerateStamina;
	FUpdateHPDelegate onUpdateHP;
	FRegenerateHPDelegate onRegenerateHP;

	UPROPERTY(BlueprintReadWrite, Category = "Your|Stamina")
	float currentStamina{ 60.0f };

	UPROPERTY(BlueprintReadWrite, Category = "Your|Stamina")
	float maxStamina{ 60.0f };

	UPROPERTY(BlueprintReadWrite, Category = "Your|Stamina")
	float StaminaRegen{ 0.1f };

	UPROPERTY(BlueprintReadWrite, Category = "Yoru|Speed")
	float walkSpeed{ 150.0f };

	UPROPERTY(BlueprintReadWrite, Category = "Your|Speed")
	float jogSpeed{ 350.0f };

	UPROPERTY(BlueprintReadWrite, Category = "Yoru|Speed")
	float runSpeed{ 600.0f };

	UPROPERTY(BlueprintReadWrite, Category = "Your|HP")
	float currentHP{ 50.0f };

	UPROPERTY(BlueprintReadWrite, Category = "Your|HP")
	float maxHP{ 100.0f };

	UPROPERTY(BlueprintReadWrite, Category = "Your|HP")
	float hpRegen{ 0.0f };

	FTimerHandle handleStamina{};
	FTimerHandle handleHP{};
};
