// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CommonAIInterface.generated.h"

UINTERFACE(MinimalAPI)
class UCommonAIInterface : public UInterface
{
	GENERATED_BODY()
};

DECLARE_DELEGATE(FCommonAIAttackFinished);
DECLARE_DELEGATE(FCommonAIBeingAttacked);


class LIESOFM_API ICommonAIInterface
{
	GENERATED_BODY()

public:
	virtual float GetAIPatrolRadius() = 0;
	virtual float GetAIDetectRange() = 0;
	virtual float GetAIAttackRange() = 0;
	virtual float GetAIRange() = 0;
	virtual float GetAITurnSpeed() = 0;

	virtual void SetAIAttackDelegate(const FCommonAIAttackFinished& InOnAttackFinished) = 0;
	virtual void SetAIBeingAttackedDelegate(const FCommonAIBeingAttacked& InOnBeingAttacked) = 0;
	virtual bool AttackByAI() = 0;
	virtual bool NoTurn() = 0;
};
