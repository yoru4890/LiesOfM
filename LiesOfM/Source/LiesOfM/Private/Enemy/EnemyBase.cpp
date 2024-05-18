// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyBase.h"

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

void AEnemyBase::ReceiveDamage(float damageAmount, AActor* attackingActor, const FHitResult& hitResult)
{
	if (DecreaseHealth(damageAmount))
	{
		Destroy();
	}
	else
	{

	}
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

