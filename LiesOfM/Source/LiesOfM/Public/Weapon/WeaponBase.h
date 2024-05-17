// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

UCLASS()
class LIESOFM_API AWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AWeaponBase();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, Category = "M|Component")
	USkeletalMeshComponent* weaponMesh;

	UPROPERTY(EditAnywhere, Category = "M|Mesh")
	USkeletalMesh* currentWeaponMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "M|AnimDataTable")
	class UDataTable* attackAnimations;

	float GetdefaultDamage()const noexcept { return defaultDamage; }



private:
	float defaultDamage{20.0f};
};
