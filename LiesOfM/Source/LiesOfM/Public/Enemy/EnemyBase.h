// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/DamageInteractions.h"
#include "EnemyBase.generated.h"

UCLASS()
class LIESOFM_API AEnemyBase : public ACharacter, public IDamageInteractions
{
	GENERATED_BODY()

public:
	AEnemyBase();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void ReceiveDamage(float damageAmount, AActor* attackingActor, const FHitResult& hitResult) override;

	UFUNCTION(BlueprintCallable)
	bool DecreaseHealth(float amount);

	UPROPERTY(BlueprintReadWrite)
	float currentHealth{80.0f};

	UPROPERTY(BlueprintReadWrite)
	float maxHealth{100.0f};
};
