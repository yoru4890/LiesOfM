// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy/EnemyBase.h"
#include "Interface/CommonAIInterface.h"
#include "EnemyCommon.generated.h"

UENUM(BlueprintType)
enum class EEnemyCommonWeapon : uint8
{
	None UMETA(DisplayName = "None"),
	Dagger UMETA(DisplayName = "Dagger"),
	Bow UMETA(DisplayName = "Bow"),

	Size UMETA(DisplayName = "Size")
};

UCLASS()
class LIESOFM_API AEnemyCommon : public AEnemyBase, public ICommonAIInterface
{
	GENERATED_BODY()

public:
	AEnemyCommon();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void ReceiveDamage(float damageAmount, AActor* attackingActor, const FHitResult& hitResult) override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy|Component")
	TObjectPtr<USkeletalMeshComponent> daggerWeapon{};

	UPROPERTY(EditAnywhere, Category = "Enemy|Montage")
	TObjectPtr<UAnimMontage> attackMontage;

	UPROPERTY(EditAnywhere, Category = "Enemy|Montage")
	TObjectPtr<UAnimMontage> hitReactionMontage;

	UPROPERTY(EditAnywhere, Category = "Enemy|Montage")
	TObjectPtr<UAnimMontage> hitReactionMontage1;

	UPROPERTY(EditAnywhere, Category = "Enemy|Montage")
	TObjectPtr<UAnimMontage> hitReactionMontage2;

	UPROPERTY(EditAnywhere, Category = "Enemy|Montage")
	TObjectPtr<UAnimMontage> hitReactionMontage3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy|Stat")
	double attackRange{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy|State")
	EEnemyCommonWeapon enemyWeapon{};

	UPROPERTY(EditAnywhere, Category = "Enemy|Weapon")
	class AWeaponBase* bow{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy|State")
	bool isAggro{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float attackCooltime{ 4.0f };
public:

	void CommonAttack();
	void SpawnBow();

	UFUNCTION(BlueprintCallable)
	void NotifyAttackEnd();

	UFUNCTION(BlueprintCallable)
	void TriggerTrace();
	void ApplyTrace();
	UFUNCTION(BlueprintCallable)
	void StopTrace();

	float CaculateDamage();

	// AI Section
protected:
	virtual float GetAIPatrolRadius() override;
	virtual float GetAIDetectRange() override;
	virtual float GetAIAttackRange() override;
	virtual float GetAIRange() override;
	virtual float GetAITurnSpeed() override;

	virtual void SetAIAttackDelegate(const FCommonAIAttackFinished& InOnAttackFinished) override;
	virtual void SetAIBeingAttackedDelegate(const FCommonAIBeingAttacked& InOnBeingAttacked) override;
	virtual bool AttackByAI() override;
	virtual bool NoTurn() override;

	FCommonAIAttackFinished OnAttackFinished;
	FCommonAIBeingAttacked OnBeingAttacked;

private:
	UPROPERTY(VisibleAnywhere, Category = "Actor")
	TArray<AActor*> hitActors{};

	FTimerHandle lineTraceTimeHandle{};

	float attackElapsedTime{};

};
