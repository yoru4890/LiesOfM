// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BossDoorManager.generated.h"

UCLASS()
class LIESOFM_API ABossDoorManager : public AActor
{
	GENERATED_BODY()
	
public:	
	ABossDoorManager();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void TriggerEnter();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Yoru")
	TObjectPtr<class AEnemyBoss> Boss{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Yoru")
	TObjectPtr<class AYoru> Player{};
};
