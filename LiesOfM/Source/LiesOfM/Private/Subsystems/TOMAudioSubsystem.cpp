// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/TOMAudioSubsystem.h"
#include "TOMDataTable.h"

void UTOMAudioSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	static ConstructorHelpers::FObjectFinder<UDataTable> weaponSoundDataFinder(TEXT("/Script/Engine.DataTable'/Game/Data/DT_WeaponSound.DT_WeaponSound'"));
	if (weaponSoundDataFinder.Succeeded())
	{
		weaponSoundDataTable = weaponSoundDataFinder.Object;
	}
}

void UTOMAudioSubsystem::Deinitialize()
{
	Super::Deinitialize();
}
