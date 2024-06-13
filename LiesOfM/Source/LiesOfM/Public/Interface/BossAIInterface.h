// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BossAIInterface.generated.h"


UINTERFACE(MinimalAPI)
class UBossAIInterface : public UInterface
{
	GENERATED_BODY()
};

DECLARE_DELEGATE(FAIRandomMoveFinished);
DECLARE_DELEGATE(FAIAttackFinished);

class LIESOFM_API IBossAIInterface
{
	GENERATED_BODY()

public:
	virtual float GetAIAttackMeleeRange() = 0;
	virtual float GetAIAttackLongRange() = 0;

	virtual void SetAIMoveFinishedDelegate(const FAIRandomMoveFinished& InOnRandomMoveFinished) = 0;
	virtual void SetAIAttackFinishedDelegate(const FAIAttackFinished& InOnAttackFinished) = 0;
	virtual void RandomMoveByAI() = 0;
	virtual bool AttackByAI() = 0;
};
