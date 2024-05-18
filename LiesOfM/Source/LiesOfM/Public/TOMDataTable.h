// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "TOMDataTable.generated.h"

USTRUCT(BlueprintType)
struct FWeaponData : public FTableRowBase
{
	GENERATED_BODY()

public:
	FWeaponData() {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim")
	TObjectPtr<UAnimMontage> runningAttackMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim")
	TObjectPtr<UAnimMontage> rollingAttackMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim")
	TObjectPtr<UAnimMontage> backStabMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim")
	TObjectPtr<UAnimMontage> riposteMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim")
	TArray<TObjectPtr<UAnimMontage>> lightAttakMontages;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim")
	TArray<TObjectPtr<UAnimMontage>> HeavyAttakMontages;
};

USTRUCT(BlueprintType)
struct FPlayerData : public FTableRowBase
{
	GENERATED_BODY()

public:
	FPlayerData() {};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim")
	TArray<TObjectPtr<UAnimMontage>> hitReactionMontages;
};

UCLASS()
class LIESOFM_API ATOMDataTable : public AActor
{
	GENERATED_BODY()
	
public:	
	ATOMDataTable();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
