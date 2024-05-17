// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "YoruBaseComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LIESOFM_API UYoruBaseComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UYoruBaseComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void SetupPlayerInputComponent(class UEnhancedInputComponent* enhancedInputComponent) {};

protected:
	UPROPERTY(VisibleAnywhere, Category = "Yoru|Reference")
	class AYoru* me;

	UPROPERTY(VisibleAnywhere, Category = "Yoru|Reference")
	class UCharacterMovementComponent* charMoveComp;
};
