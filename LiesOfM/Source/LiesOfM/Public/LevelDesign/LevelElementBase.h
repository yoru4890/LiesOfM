// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelElementBase.generated.h"

UCLASS()
class LIESOFM_API ALevelElementBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ALevelElementBase();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
};
