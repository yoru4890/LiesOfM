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
	Hammer UMETA(DisplayName = "Hammer"),

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

	virtual void ReceiveDamage(float damageAmount, AActor* attackingActor, const FHitResult& hitResult, bool isRedAttack) override;

	virtual void ReceiveGroggyDamage(float damageAmount, AActor* attackingActor) override;

	virtual bool CanGrabAttacked() override;

	virtual void GrabAttacked(bool isFront) override;

	virtual void CaculateDamage(float damage) override;

	virtual void Groggy() override;
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy|Component")
	TObjectPtr<USkeletalMeshComponent> daggerWeapon{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy|Component")
	TObjectPtr<USkeletalMeshComponent> hammerWeapon{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy|Component")
	TObjectPtr<class UNiagaraComponent> redAttackBody{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy|Component")
	TObjectPtr<class UNiagaraComponent> redAttackHammer{};

	UPROPERTY(EditAnywhere, Category = "Enemy|Montage")
	TObjectPtr<UAnimMontage> attackDaggerMontage;

	UPROPERTY(EditAnywhere, Category = "Enemy|Montage")
	TObjectPtr<UAnimMontage> attackHammerMontage;

	UPROPERTY(EditAnywhere, Category = "Enemy|Montage")
	TObjectPtr<UAnimMontage> hitReactionMontage;

	UPROPERTY(EditAnywhere, Category = "Enemy|Montage")
	TObjectPtr<UAnimMontage> hitReactionMontage1;

	UPROPERTY(EditAnywhere, Category = "Enemy|Montage")
	TObjectPtr<UAnimMontage> hitReactionMontage2;

	UPROPERTY(EditAnywhere, Category = "Enemy|Montage")
	TObjectPtr<UAnimMontage> hitReactionMontage3;

	UPROPERTY(EditAnywhere, Category = "Enemy|Montage")
	TObjectPtr<UAnimMontage> grabAttackedFrontMontage;

	UPROPERTY(EditAnywhere, Category = "Enemy|Montage")
	TObjectPtr<UAnimMontage> grabAttackedBackMontage;

	UPROPERTY(EditAnywhere, Category = "Enemy|Montage")
	TObjectPtr<UAnimMontage> groggyMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy|Stat")
	double attackRange{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy|State")
	EEnemyCommonWeapon enemyWeapon{};

	UPROPERTY(EditAnywhere, Category = "Enemy|Weapon")
	class AWeaponBase* bow{};

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	TObjectPtr<class UNiagaraSystem> bloodFX;

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

	UFUNCTION(BlueprintCallable)
	void ShowRedAttack();

	UFUNCTION(BlueprintCallable)
	void HiddenRedAttack();

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

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float maxHP{ 100.0f };
	float currentHP{ 100.0f };
	float totalDamage{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UWidgetComponent* widgetHP{};

	UPROPERTY(EditAnywhere, Category = "Yoru|Widget")
	class UProgressBar* HPBar;

	UPROPERTY(EditAnywhere, Category = "Yoru|Widget")
	class UTextBlock* DamageText;
	
	void InitWidget();
	void TriggerWidget(float damage);
	void HiddenDamageText();
	void HiddenHPBar();
	void Dead();



	FTimerHandle damageTextTimeHandle{};
	FTimerHandle HPBarTimeHandle{};
};
