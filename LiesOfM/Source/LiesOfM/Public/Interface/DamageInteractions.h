// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DamageInteractions.generated.h"

UINTERFACE(MinimalAPI)
class UDamageInteractions : public UInterface
{
	GENERATED_BODY()
};

class LIESOFM_API IDamageInteractions
{
	GENERATED_BODY()

public:
	virtual void ReceiveDamage(float damageAmount, AActor* attackingActor, const FHitResult& hitResult, bool isRedAttack) = 0;

	virtual void ReceiveGroggyDamage(float damageAmount, AActor* attackingActor) = 0;
};
