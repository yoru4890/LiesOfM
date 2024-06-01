// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/TOMAudioSubsystem.h"
#include "TOMDataTable.h"

UTOMAudioSubsystem::UTOMAudioSubsystem()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> weaponSoundDataFinder(TEXT("/Script/Engine.DataTable'/Game/Data/DT_WeaponSound.DT_WeaponSound'"));
	if (weaponSoundDataFinder.Succeeded())
	{
		weaponSoundDataTable = weaponSoundDataFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UDataTable> hurtSoundDataFinder(TEXT("/Script/Engine.DataTable'/Game/Data/DT_HurtSoundData.DT_HurtSoundData'"));
	if (hurtSoundDataFinder.Succeeded())
	{
		hurtSoundDataTable = hurtSoundDataFinder.Object;
	}
}

void UTOMAudioSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UTOMAudioSubsystem::Deinitialize()
{
	Super::Deinitialize();
}