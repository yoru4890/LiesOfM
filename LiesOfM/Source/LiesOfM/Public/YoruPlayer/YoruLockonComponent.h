// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "YoruPlayer/YoruBaseComponent.h"
#include "InputActionvalue.h"
#include "YoruLockonComponent.generated.h"

UCLASS()
class LIESOFM_API UYoruLockonComponent : public UYoruBaseComponent
{
	GENERATED_BODY()
	
public:
	UYoruLockonComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void SetupPlayerInputComponent(class UEnhancedInputComponent* enhancedInputComponent) override;

	void TryLockon();

	bool CheckTrace();

	AActor* FindFrontClosedOne();
	AActor* FindLeftClosedOne();
	AActor* FindRightClosedOne();

	void LookTarget();
	void StopLockon();
	void ChangeLockon(const FInputActionValue& value);

private:
	TArray<FHitResult> outHits;
	float radius{700.0f};
	UPROPERTY(VisibleAnywhere, Category = "Yoru|Input")
	TObjectPtr<class UInputAction> lockonAction;

	UPROPERTY(VisibleAnywhere, Category = "Yoru|Input")
	TObjectPtr<class UInputAction> lockonChangeAction;
	class AEnemyBase* lockonTarget{};

	FTimerHandle lockonTimer{};
};
