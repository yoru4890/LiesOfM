// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy/EnemyBase.h"
#include "EnemyCommon.generated.h"

/**
 * 
 */
UCLASS()
class LIESOFM_API AEnemyCommon : public AEnemyBase
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category ="Enemy|Component")
	TObjectPtr<USkeletalMeshComponent> weaponComp{};

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
public:

	void CommonAttack();
};
