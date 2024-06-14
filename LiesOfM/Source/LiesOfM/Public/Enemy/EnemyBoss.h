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

	void InitContents();

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

	UFUNCTION(BlueprintCallable)
	void ChangeLockonPlayer(bool InisLockon);

	UFUNCTION(BlueprintCallable)
	void NotifyAttackEnd();

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

	UFUNCTION(BlueprintCallable)
	void ChangeDamage(float damage);

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy|Component")
	TObjectPtr<USkeletalMeshComponent> weapon{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy|Component")
	TObjectPtr<class UNiagaraComponent> redAttackBody{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy|Component")
	TObjectPtr<class UNiagaraComponent> redAttackWeapon{};

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	TObjectPtr<class UNiagaraSystem> bloodFX;
private:
	bool isLockon{ true };
	bool isRedAttack{};
	int phase{};
	float resultDamage{ 20.0f };
	float turnSpeed{5.0f};
	float redAttackTurnSpeed{ 10.0f };
	float normalTurnSpeed{ 5.0f };
	TObjectPtr<class AEnemyBossAIController> BossAIController{};

	TObjectPtr<APawn> Player{};

	UPROPERTY(VisibleAnywhere, Category = "Actor")
	TArray<AActor*> hitActors{};

	FTimerHandle lineTraceTimeHandle{};

	UPROPERTY(EditAnywhere, Category = "Enemy|Montage")
	TObjectPtr<UAnimMontage> meleeAttack1Montage;

	UPROPERTY(EditAnywhere, Category = "Enemy|Montage")
	TObjectPtr<UAnimMontage> meleeAttack2Montage;

	UPROPERTY(EditAnywhere, Category = "Enemy|Montage")
	TObjectPtr<UAnimMontage> meleeAttack3Montage;

	UPROPERTY(EditAnywhere, Category = "Enemy|Montage")
	TObjectPtr<UAnimMontage> rushAttackMontage;

	UPROPERTY(EditAnywhere, Category = "Enemy|Montage")
	TObjectPtr<UAnimMontage> jumpAttackMontage;

	UPROPERTY(EditAnywhere, Category = "Enemy|Montage")
	TObjectPtr<UAnimMontage> counterBlockMontage;

	UPROPERTY(EditAnywhere, Category = "Enemy|Montage")
	TObjectPtr<UAnimMontage> counterAttackMontage;

	UPROPERTY(EditAnywhere, Category = "Enemy|Montage")
	TObjectPtr<UAnimMontage> changePhaseMontage;

	UPROPERTY(EditAnywhere, Category = "Enemy|Montage")
	TObjectPtr<UAnimMontage> groggyMontage;

	UPROPERTY(EditAnywhere, Category = "Enemy|Montage")
	TObjectPtr<UAnimMontage> grabAttackedFrontMontage;

	UPROPERTY(EditAnywhere, Category = "Enemy|Montage")
	TObjectPtr<UAnimMontage> grabAttackedBackMontage;

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
