// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "YoruPlayer/YoruBaseComponent.h"
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

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Yoru | Hit")
	bool isHittable{true};

	FTimerHandle invincibilityTimeHandle{};
};
