// Fill out your copyright notice in the Description page of Project Settings.


#include "YoruPlayer/YoruMoveComponent.h"
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include <InputMappingContext.h>

UYoruMoveComponent::UYoruMoveComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	

}

void UYoruMoveComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UYoruMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UYoruMoveComponent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	


}

void UYoruMoveComponent::InitializeComponent()
{
	Super::InitializeComponent();

	
}

void UYoruMoveComponent::Move(const FInputActionValue& value)
{
	
}
