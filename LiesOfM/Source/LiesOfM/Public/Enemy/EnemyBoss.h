// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy/EnemyBase.h"
#include "Interface/BossAIInterface.h"
#include "EnemyBoss.generated.h"

/**
 * 
 */
UCLASS()
class LIESOFM_API AEnemyBoss : public AEnemyBase, public IBossAIInterface
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



	void ChangePhase();

	// Attack
	void Attack();
	void CounterAttack();
	void RushAttack();
	void JumpAttack();
	void meleeAttack1();
	void meleeAttack2();
	void meleeAttack3();

	UFUNCTION(BlueprintCallable)
	void TriggerTrace();
	void ApplyTrace();
	UFUNCTION(BlueprintCallable)
	void StopTrace();

	UFUNCTION(BlueprintCallable)
	void ShowRedAttack();

	UFUNCTION(BlueprintCallable)
	void HiddenRedAttack();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy|Component")
	TObjectPtr<USkeletalMeshComponent> weapon{};

private:
	int phase{};

	// AI
public:
	FAIRandomMoveFinished OnRandomMoveFinished{};
	FAIAttackFinished OnAttackFinished{};

	virtual float GetAIAttackMeleeRange() override;
	virtual float GetAIAttackLongRange() override;

	virtual void SetAIMoveFinishedDelegate(const FAIRandomMoveFinished& InOnRandomMoveFinished) override;
	virtual void SetAIAttackFinishedDelegate(const FAIAttackFinished& InOnAttackFinished) override;
	virtual void RandomMoveByAI() override;
	virtual bool AttackByAI() override;

	void StopRandomMove();
};
