// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "YoruPlayer/YoruBaseComponent.h"
#include "YoruStatComponent.generated.h"

/**
 * 
 */
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
};
