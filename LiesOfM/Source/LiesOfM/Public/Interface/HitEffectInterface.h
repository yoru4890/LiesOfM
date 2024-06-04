// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HitEffectInterface.generated.h"

UINTERFACE(Blueprintable)
class UHitEffectInterface : public UInterface
{
	GENERATED_BODY()
};

class LIESOFM_API IHitEffectInterface
{
	GENERATED_BODY()

	
public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Trigger Reaction")
	void ReactToEffect(FVector location);
};
