// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyBoss.h"

AEnemyBoss::AEnemyBoss()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> meshFinder(TEXT("/Script/Engine.SkeletalMesh'/Game/AAA/Animations/Enemy/Boss1/Uriel_A_Plotexia.Uriel_A_Plotexia'"));

	if (meshFinder.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(meshFinder.Object);
		GetMesh()->SetRelativeLocationAndRotation({ 0.0,0.0,-90.0 }, { 0.0,-90.0,0.0 });
	}

	static ConstructorHelpers::FClassFinder<UAnimInstance> animFinder(TEXT("/Script/Engine.AnimBlueprint'/Game/AAA/Blueprints/Enemy/Boss/ABP_EnemyBoss.ABP_EnemyBoss_C'"));

	if (animFinder.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(animFinder.Class);
	}
}

void AEnemyBoss::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemyBoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemyBoss::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AEnemyBoss::ReceiveDamage(float damageAmount, AActor* attackingActor, const FHitResult& hitResult)
{
	Super::ReceiveDamage(damageAmount, attackingActor, hitResult);
}

void AEnemyBoss::ReceiveGroggyDamage(float damageAmount, AActor* attackingActor)
{
	Super::ReceiveGroggyDamage(damageAmount, attackingActor);
}

bool AEnemyBoss::CanGrabAttacked()
{
	Super::CanGrabAttacked();
	return false;
}

void AEnemyBoss::GrabAttacked(bool isFront)
{
	Super::GrabAttacked(isFront);
}

void AEnemyBoss::Groggy()
{
	Super::Groggy();
}

void AEnemyBoss::CaculateDamage(float damage)
{
	Super::CaculateDamage(damage);
}
