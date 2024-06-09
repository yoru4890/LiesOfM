// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "YoruPlayer/YoruBaseComponent.h"
#include "InputActionvalue.h"
#include "YoruDefenceComponent.generated.h"

UCLASS()
class LIESOFM_API UYoruDefenceComponent : public UYoruBaseComponent
{
	GENERATED_BODY()
	
public:
	UYoruDefenceComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void SetupPlayerInputComponent(class UEnhancedInputComponent* enhancedInputComponent) override;

public:
	void HitReaction(float damageAmount, AActor* attackingActor, const FHitResult& hitResult);
	void HandleHit();
	void SetInvincibilityTime(float duration);
	void ChangeHittable();
	void Block();
	void UnBlock();
	void ChangeParrying();
	void InitAnimNotify();
	bool CheckParrying() const noexcept;
	void CaculateBlock(float& damageAmount);
	bool Parry(float& damageAmount);
	void InitData();
	void InitFX();
	FVector CaculateParryPoint(const FVector& impactPoint);

private:
	UPROPERTY(VisibleAnywhere, Category = "Yoru|Input")
	TObjectPtr<class UInputAction> blockAction;

	UPROPERTY(EditAnywhere, Category = "Yoru|Montage")
	TObjectPtr<UAnimMontage> blockMontage;

	TArray<USoundBase*> parryingSound{};
	TArray<USoundBase*> blockingSound{};
	TArray<USoundBase*> blockFailSound{};
	TArray<USoundBase*> hurtSound{};
	TArray<USoundBase*> deadSound{};
	TArray<UAnimMontage*> hitReactions{};

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Yoru | Hit")
	bool isHittable{true};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Yoru | Hit")
	bool isParrying{};

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	TObjectPtr<class UNiagaraSystem> parryingFX;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	TObjectPtr<class UNiagaraSystem> blockingFX;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	TObjectPtr<class UNiagaraSystem> bloodFX;

	FTimerHandle invincibilityTimeHandle{};
	FTimerHandle parryingTimeHandle{};
};
