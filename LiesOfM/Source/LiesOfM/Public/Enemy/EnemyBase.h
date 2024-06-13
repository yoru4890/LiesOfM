// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/DamageInteractions.h"
#include "EnemyBase.generated.h"

UENUM(BlueprintType)
enum class EEnemyState : uint8
{
	None UMETA(DisplayName = "None"),
	Attacking UMETA(DisplayName = "Attack"),
	BeingAttacked UMETA(DisplayName = "BeingAttacked"),
	Groggy UMETA(DisplayName = "Groggy"),
	GrabAttacked UMETA(DisplayName = "GrabAttacked"),

	SIZE UMETA(DisplayName = "SIZE")
};


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

	virtual void ReceiveGroggyDamage(float damageAmount, AActor* attackingActor) override {};

	virtual bool CanGrabAttacked() { return false; };

	virtual void GrabAttacked(bool isFront) {};

	virtual void Groggy() {};

	UFUNCTION(BlueprintCallable)
	void SetInvincibilityTime(float duration);

	UFUNCTION(BlueprintCallable)
	virtual void CaculateDamage(float damage) {};

	UFUNCTION(BlueprintCallable)
	bool DecreaseHealth(float amount);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float currentHealth{80.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float maxHealth{100.0f};

	UPROPERTY(BlueprintReadWrite)
	EEnemyState currentEnemyState{ EEnemyState::None };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isDead{};

	UPROPERTY(BlueprintReadWrite)
	float currentGroggy{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy|Stat")
	float maxGroggy{ 100.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy|State")
	bool isElite{};

	bool isHittable{ true };
};
