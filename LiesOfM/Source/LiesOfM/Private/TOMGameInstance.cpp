// Fill out your copyright notice in the Description page of Project Settings.


#include "TOMGameInstance.h"

UTOMGameInstance::UTOMGameInstance(const FObjectInitializer& ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UDataTable> playerDataFinder(TEXT("/Script/Engine.DataTable'/Game/Data/DT_Player.DT_Player'"));
	if (playerDataFinder.Succeeded())
	{
		playerDataTable = playerDataFinder.Object;
	}
}

void UTOMGameInstance::Init()
{
	Super::Init();
}
