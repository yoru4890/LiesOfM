// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TOMGameInstance.generated.h"

UCLASS()
class LIESOFM_API UTOMGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UTOMGameInstance(const FObjectInitializer& ObjectInitializer);

	virtual void Init() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "M|DataTable")
	class UDataTable* playerDataTable{};
};
