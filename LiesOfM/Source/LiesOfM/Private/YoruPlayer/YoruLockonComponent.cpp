// Fill out your copyright notice in the Description page of Project Settings.


#include "YoruPlayer/YoruLockonComponent.h"
#include "YoruPlayer/Yoru.h"
#include "Kismet/KismetSystemLibrary.h"
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include <InputMappingContext.h>
#include "Camera/CameraComponent.h"

UYoruLockonComponent::UYoruLockonComponent()
{
	static ConstructorHelpers::FObjectFinder<UInputAction> lockonActionFinder(TEXT("/Script/EnhancedInput.InputAction'/Game/AAA/Input/IA_Lockon.IA_Lockon'"));

	if (lockonActionFinder.Succeeded())
	{
		lockonAction = lockonActionFinder.Object;
	}
}

void UYoruLockonComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UYoruLockonComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UYoruLockonComponent::SetupPlayerInputComponent(UEnhancedInputComponent* enhancedInputComponent)
{
	enhancedInputComponent->BindAction(lockonAction, ETriggerEvent::Started, this, &UYoruLockonComponent::TryLockon);
}

void UYoruLockonComponent::TryLockon()
{
	if (!(me->GetIsLockon()))
	{
		if (CheckTrace())
		{
			lockonTarget = FindFrontClosedOne();
			if (lockonTarget)
			{
				me->SetIsLockon(true);
				GetWorld()->GetTimerManager().SetTimer(lockonTimer, this, &UYoruLockonComponent::LookTarget, GetWorld()->GetDeltaSeconds(), true);
			}
			else
			{
				
			}
		}
		else
		{

		}
	}
	else
	{
		StopLockon();
	}
}

bool UYoruLockonComponent::CheckTrace()
{
	FVector start{ me->GetActorLocation() };
	FVector end{ me->GetActorLocation() };
	TArray<AActor*> ignoreActors;

	return UKismetSystemLibrary::SphereTraceMulti(GetWorld(), start, end, radius, ETraceTypeQuery::TraceTypeQuery5, false, ignoreActors, EDrawDebugTrace::ForDuration, outHits, true);
}

AActor* UYoruLockonComponent::FindFrontClosedOne()
{
	AActor* tempTarget{};
	float minDistance{ 700.0f };

	for (const FHitResult& hitResult : outHits)
	{
		FVector hitdirection{ (hitResult.GetActor()->GetActorLocation() - me->GetActorLocation()).GetSafeNormal2D() };
		double distance{ (hitResult.GetActor()->GetActorLocation() - me->GetActorLocation()).Length() };
		FVector direction{ me->GetActorRotation().Vector().GetSafeNormal2D() };
		double degree{ FMath::RadiansToDegrees(FMath::Acos((FVector::DotProduct(direction, hitdirection)))) };
		if (degree < 30.0f)
		{
			if (minDistance >= distance)
			{
				minDistance = distance;
				lockonTarget = hitResult.GetActor();
			}
		}
	}

	return lockonTarget;
}

void UYoruLockonComponent::LookTarget()
{
	FVector start{ me->mainCamera->GetComponentLocation() };
	FVector end{ lockonTarget->GetActorLocation() };
	end.Z = (end.Z - (end - start).Length() / 5);

	me->GetController()->SetControlRotation((end - start).Rotation());
	
}

void UYoruLockonComponent::StopLockon()
{
	me->SetIsLockon(false);
	lockonTarget = nullptr;
	GetWorld()->GetTimerManager().ClearTimer(lockonTimer);
}
