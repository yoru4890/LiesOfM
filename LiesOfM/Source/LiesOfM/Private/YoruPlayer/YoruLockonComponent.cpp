// Fill out your copyright notice in the Description page of Project Settings.


#include "YoruPlayer/YoruLockonComponent.h"
#include "YoruPlayer/Yoru.h"
#include "Components/WidgetComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include <InputMappingContext.h>
#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Enemy/EnemyBase.h"
#include "YoruPlayer/YoruMoveComponent.h"

UYoruLockonComponent::UYoruLockonComponent()
{
	static ConstructorHelpers::FObjectFinder<UInputAction> lockonActionFinder(TEXT("/Script/EnhancedInput.InputAction'/Game/AAA/Input/IA_Lockon.IA_Lockon'"));

	if (lockonActionFinder.Succeeded())
	{
		lockonAction = lockonActionFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> lockonChangeActionFinder(TEXT("/Script/EnhancedInput.InputAction'/Game/AAA/Input/IA_LockonChange.IA_LockonChange'"));

	if (lockonChangeActionFinder.Succeeded())
	{
		lockonChangeAction = lockonChangeActionFinder.Object;
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
	enhancedInputComponent->BindAction(lockonChangeAction, ETriggerEvent::Started, this, &UYoruLockonComponent::ChangeLockon);
}

void UYoruLockonComponent::TryLockon()
{
	if (!(me->GetIsLockon()))
	{
		if (CheckTrace())
		{
			lockonTarget = Cast<AEnemyBase>(FindFrontClosedOne());
			if (lockonTarget)
			{
				me->SetIsLockon(true);
				me->lockonWidget->SetVisibility(true);
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
	ignoreActors.Add(lockonTarget);

	return UKismetSystemLibrary::SphereTraceMulti(GetWorld(), start, end, radius, ETraceTypeQuery::TraceTypeQuery5, false, ignoreActors, EDrawDebugTrace::None, outHits, true);
}

AActor* UYoruLockonComponent::FindFrontClosedOne()
{
	AActor* hitActor{};
	float minDistance{ 2200.0f };

	for (const FHitResult& hitResult : outHits)
	{
		FVector hitdirection{ (hitResult.GetActor()->GetActorLocation() - me->mainCamera->GetComponentLocation()).GetSafeNormal2D() };
		double distance{ (hitResult.GetActor()->GetActorLocation() - me->mainCamera->GetComponentLocation()).Length() };
		FVector direction{ me->mainCamera->GetComponentRotation().Vector().GetSafeNormal2D() };
		double degree{ FMath::RadiansToDegrees(FMath::Acos((FVector::DotProduct(direction, hitdirection)))) };
		if (degree < 15.0f)
		{

			if (minDistance >= distance)
			{
				minDistance = distance;
				hitActor = hitResult.GetActor();
			}
		}
	}

	return hitActor;
}

AActor* UYoruLockonComponent::FindLeftClosedOne()
{
	AActor* hitActor{};
	float minDistance{ 900.0f };

	for (const FHitResult& hitResult : outHits)
	{
		FVector hitdirection{ (hitResult.GetActor()->GetActorLocation() - me->mainCamera->GetComponentLocation()).GetSafeNormal2D() };
		double distance{ (hitResult.GetActor()->GetActorLocation() - lockonTarget->GetActorLocation()).Length() };
		FVector direction{ me->mainCamera->GetComponentRotation().Vector().GetSafeNormal2D() };
		FVector rightDirection{ FRotationMatrix(me->mainCamera->GetComponentRotation()).GetScaledAxis(EAxis::Y).GetSafeNormal2D() };
		double rightDotResult{ FVector::DotProduct(rightDirection, hitdirection) };
		double degree{ FMath::RadiansToDegrees(FMath::Acos((FVector::DotProduct(direction, hitdirection)))) };
		if (rightDotResult < 0)
		{
			degree *= -1;
		}
		if (degree < 0)
		{
			if (minDistance >= distance)
			{
				minDistance = distance;
				hitActor = hitResult.GetActor();
			}
		}
	}

	if (hitActor)
	{
		return hitActor;
	}
	else
	{
		return lockonTarget;
	}
}

AActor* UYoruLockonComponent::FindRightClosedOne()
{
	AActor* hitActor{};
	float minDistance{ 900.0f };

	for (const FHitResult& hitResult : outHits)
	{
		FVector hitdirection{ (hitResult.GetActor()->GetActorLocation() - me->mainCamera->GetComponentLocation()).GetSafeNormal2D() };
		double distance{ (hitResult.GetActor()->GetActorLocation() - lockonTarget->GetActorLocation()).Length() };
		FVector direction{ me->mainCamera->GetComponentRotation().Vector().GetSafeNormal2D() };
		FVector rightDirection{ FRotationMatrix(me->mainCamera->GetComponentRotation()).GetScaledAxis(EAxis::Y).GetSafeNormal2D() };
		double rightDotResult{ FVector::DotProduct(rightDirection, hitdirection) };
		double degree{ FMath::RadiansToDegrees(FMath::Acos((FVector::DotProduct(direction, hitdirection)))) };
		if (rightDotResult < 0)
		{
			degree *= -1;
		}
		if (degree > 0)
		{
			if (minDistance >= distance)
			{
				minDistance = distance;
				hitActor = hitResult.GetActor();
			}
		}
	}

	if (hitActor)
	{
		return hitActor;
	}
	else
	{
		return lockonTarget;
	}
}

void UYoruLockonComponent::LookTarget()
{
	FVector start{ me->mainCamera->GetComponentLocation() };
	FVector end{ lockonTarget->GetActorLocation() };
	FRotator result{ (end - start).Rotation() };
	result.Pitch -= 10.0f;
	if (result.Pitch <= -30.0f)
	{
		result.Pitch = -30.0f;
	}

	me->GetController()->SetControlRotation(FMath::RInterpTo(me->GetControlRotation(), result, GetWorld()->GetDeltaSeconds(), 10.0f));


	me->lockonWidget->SetWorldLocation(lockonTarget->GetMesh()->GetBoneLocation(TEXT("Spine2")));

	if (lockonTarget->isDead)
	{
		StopLockon();
	}
}

void UYoruLockonComponent::StopLockon()
{
	me->SetIsLockon(false);
	me->lockonWidget->SetVisibility(false);
	lockonTarget = nullptr;
	GetWorld()->GetTimerManager().ClearTimer(lockonTimer);
}

void UYoruLockonComponent::ChangeLockon(const FInputActionValue& value)
{
	if (me->GetIsLockon())
	{
		if (CheckTrace())
		{
			double valueY{value.Get<float>()};

			if (valueY < 0)
			{
				lockonTarget = Cast<AEnemyBase>(FindLeftClosedOne());
			}
			else if (valueY > 0)
			{
				lockonTarget = Cast<AEnemyBase>(FindRightClosedOne());
			}

			if (lockonTarget)
			{
				me->SetIsLockon(true);
				me->lockonWidget->SetVisibility(true);
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
}
