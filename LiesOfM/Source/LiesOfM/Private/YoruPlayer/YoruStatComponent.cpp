// Fill out your copyright notice in the Description page of Project Settings.


#include "YoruPlayer/YoruStatComponent.h"
#include "YoruPlayer/Yoru.h"
#include "YoruPlayer/YoruMoveComponent.h"
#include "YoruPlayer/YoruWidgetComponent.h"


UYoruStatComponent::UYoruStatComponent()
{
}

void UYoruStatComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UYoruStatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

float UYoruStatComponent::DecreaseStamina(float amount)
{
	currentStamina -= amount;

	if (currentStamina < 0)
	{
		currentStamina = 0;
	}

	onUpdateStamina.Broadcast();

	return currentStamina;
}

float UYoruStatComponent::DecreaseHP(float amount)
{
	currentHP -= amount;

	if (currentHP < 0)
	{
		currentHP = 0;
		me->moveComp->Die();
	}

	onUpdateHP.Broadcast();

	return currentHP;
}

float UYoruStatComponent::GetStaminaRatio()
{
	return currentStamina / maxStamina;
}

float UYoruStatComponent::GetHPRatio()
{
	return currentHP / maxHP;
}

bool UYoruStatComponent::CheckStamina(float staminaNeeded) const noexcept
{
	return currentStamina >= staminaNeeded;
}

void UYoruStatComponent::HandleStaminaRegen(bool isStartRegen, float duration)
{
	if (isStartRegen)
	{
		GetWorld()->GetTimerManager().SetTimer(handleStamina, this, &UYoruStatComponent::CallRegenerateStartStamina, 0.05f, true, duration);
	}
	else
	{
		GetWorld()->GetTimerManager().ClearTimer(handleStamina);
		CallRegenerateStopStamina();
	}
}

void UYoruStatComponent::HandleHPRegen(bool isStartRegen, float duration)
{
	if (isStartRegen)
	{
		GetWorld()->GetTimerManager().SetTimer(handleHP, this, &UYoruStatComponent::CallRegenerateStartHP, 0.05f, true, duration);
	}
	else
	{
		GetWorld()->GetTimerManager().ClearTimer(handleHP);
		CallRegenerateStopHP();
	}
}

void UYoruStatComponent::RunTick()
{
	if (currentStamina > 0.0f)
	{
		DecreaseStamina(0.1f);
		CallUpdateStamina();
	}
	else
	{
		me->moveComp->StopRunning();
	}
}

void UYoruStatComponent::CaculateStaminaRegen()
{
	if (GetStaminaRatio() >= 1.0)
	{
		CallRegenerateStopStamina();
		currentStamina = maxStamina;
	}
	else
	{
		currentStamina += StaminaRegen;
	}
	CallUpdateStamina();
}

void UYoruStatComponent::CaculateHPRegen()
{
	if (GetHPRatio() >= 1.0)
	{
		CallRegenerateStopHP();
		currentHP = maxHP;
	}
	else
	{
		currentHP += hpRegen;
	}
	CallUpdateHP();
}
