// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy/EnemyBase.h"
#include "EnemyBoss.generated.h"

/**
 * 
 */
UCLASS()
class LIESOFM_API AEnemyBoss : public AEnemyBase
{
	GENERATED_BODY()
	
public:
	AEnemyBoss();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void ReceiveDamage(float damageAmount, AActor* attackingActor, const FHitResult& hitResult) override;

	virtual void ReceiveGroggyDamage(float damageAmount, AActor* attackingActor) override;

	virtual bool CanGrabAttacked() override;

	virtual void GrabAttacked(bool isFront) override;

	virtual void Groggy() override;

	virtual void CaculateDamage(float damage) override;
};
