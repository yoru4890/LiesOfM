// Fill out your copyright notice in the Description page of Project Settings.


#include "YoruPlayer/YoruAnimInstance.h"
#include "YoruPlayer/Yoru.h"

UYoruAnimInstance::UYoruAnimInstance()
{
}

void UYoruAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	owner = Cast<AYoru>(GetOwningActor());
}

void UYoruAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
}
