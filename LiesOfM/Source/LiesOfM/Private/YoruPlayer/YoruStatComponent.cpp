// Fill out your copyright notice in the Description page of Project Settings.


#include "YoruPlayer/YoruStatComponent.h"
#include "YoruPlayer/Yoru.h"


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

	return currentStamina;
}

float UYoruStatComponent::GetStaminaRatio()
{
	return currentStamina / maxStamina;
}

void UYoruStatComponent::TempTemp()
{
	onUpdateStamina.Broadcast();
	onRegenerateStamina.Broadcast(true);
}
