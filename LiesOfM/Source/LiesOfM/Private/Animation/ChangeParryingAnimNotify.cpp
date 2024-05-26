// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/ChangeParryingAnimNotify.h"

void UChangeParryingAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	onNotified.Broadcast();
}
