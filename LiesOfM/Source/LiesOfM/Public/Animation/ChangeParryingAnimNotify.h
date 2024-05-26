// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "ChangeParryingAnimNotify.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnNotifiedStartParry);

UCLASS()
class LIESOFM_API UChangeParryingAnimNotify : public UAnimNotify
{
	GENERATED_BODY()

public:
	FOnNotifiedStartParry onNotified;
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
};
