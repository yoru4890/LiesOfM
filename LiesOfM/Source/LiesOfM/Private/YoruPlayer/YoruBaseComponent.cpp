// Fill out your copyright notice in the Description page of Project Settings.

#include "YoruPlayer/YoruBaseComponent.h"

UYoruBaseComponent::UYoruBaseComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	me = Cast<AYoru>(GetOwner());
}

void UYoruBaseComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UYoruBaseComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UYoruBaseComponent::InitializeComponent()
{
	Super::InitializeComponent();
}
