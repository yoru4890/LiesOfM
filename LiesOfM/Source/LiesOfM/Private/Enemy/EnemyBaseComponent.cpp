// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyBaseComponent.h"
#include "Enemy/EnemyBase.h"

UEnemyBaseComponent::UEnemyBaseComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UEnemyBaseComponent::BeginPlay()
{
	Super::BeginPlay();
	me = Cast<AEnemyBase>(GetOwner());
}


void UEnemyBaseComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

