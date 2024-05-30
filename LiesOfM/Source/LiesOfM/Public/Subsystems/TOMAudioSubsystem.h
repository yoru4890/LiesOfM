// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TOMAudioSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class LIESOFM_API UTOMAudioSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	

public:
	UTOMAudioSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	void PlaySound(USoundBase* sound);
	void PlaySoundAtLocation(USoundBase* sound, const FVector& location);

public:
	UPROPERTY(EditAnywhere, Category = "Data")
	class UDataTable* weaponSoundDataTable;
};
