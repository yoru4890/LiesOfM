// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyBase.h"
#include "YoruPlayer/Yoru.h"
#include "YoruPlayer/YoruLockonComponent.h"

AEnemyBase::AEnemyBase()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyBase::ReceiveDamage(float damageAmount, AActor* attackingActor, const FHitResult& hitResult, bool isRedAttack)
{
	if (DecreaseHealth(damageAmount))
	{
		Destroy();
		Cast<AYoru>(attackingActor)->lockonComp->StopLockon();
	}
	else
	{

	}
}

float AEnemyBase::GetHPRatio()
{
	return currentHealth / maxHealth;
}

void AEnemyBase::SetInvincibilityTime(float duration)
{
	isHittable = false;
	FTimerHandle invincibilityTimeHandle{};
	GetWorld()->GetTimerManager().SetTimer(invincibilityTimeHandle, [this]()
		{
			isHittable = true;
		}, 0.01f, false, duration);
}

bool AEnemyBase::DecreaseHealth(float amount)
{
	currentHealth -= amount;
	if (currentHealth <= 0)
	{
		currentHealth = 0;
		return true;
	}

	return false;
}

