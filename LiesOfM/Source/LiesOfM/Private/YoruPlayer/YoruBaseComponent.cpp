// Fill out your copyright notice in the Description page of Project Settings.

#include "YoruPlayer/YoruBaseComponent.h"
#include "YoruPlayer/Yoru.h"

UYoruBaseComponent::UYoruBaseComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	
}

void UYoruBaseComponent::BeginPlay()
{
	Super::BeginPlay();
	me = Cast<AYoru>(GetOwner());
	charMoveComp = me->GetCharacterMovement();
}

void UYoruBaseComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}
