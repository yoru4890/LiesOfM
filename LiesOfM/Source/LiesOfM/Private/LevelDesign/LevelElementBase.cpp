// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelDesign/LevelElementBase.h"

ALevelElementBase::ALevelElementBase()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ALevelElementBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ALevelElementBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

