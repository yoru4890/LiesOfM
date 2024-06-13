// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/BossDoorManager.h"
#include "Enemy/EnemyBoss.h"
#include "YoruPlayer/Yoru.h"
#include "Kismet/GameplayStatics.h"
#include "Enemy/EnemyBossAIController.h"

ABossDoorManager::ABossDoorManager()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ABossDoorManager::BeginPlay()
{
	Super::BeginPlay();
	
	Player = Cast<AYoru>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (!Player)
	{
		UE_LOG(LogTemp, Warning, TEXT("BossDoor::NoPlayer"));
	}
}

void ABossDoorManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABossDoorManager::TriggerEnter()
{
	AEnemyBossAIController* BossController = Cast<AEnemyBossAIController>(Boss->GetController());
	BossController->RunAI();
	// 보스 AI 동작 , Widget 동작
	// Player Anim 동작
}

