// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/BossDoorManager.h"
#include "Enemy/EnemyBoss.h"
#include "YoruPlayer/Yoru.h"
#include "Kismet/GameplayStatics.h"
#include "Enemy/EnemyBossAIController.h"
#include "Enemy/BossWidget.h"

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
	Boss->SetVisible(true);
	AEnemyBossAIController* BossController = Cast<AEnemyBossAIController>(Boss->GetController());
	BossController->RunAI();
	Boss->widgetComp->ShowWidget();
	// Player Anim µø¿€
}

