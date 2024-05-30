// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/TOMAudioSubsystem.h"
#include "TOMDataTable.h"

UTOMAudioSubsystem::UTOMAudioSubsystem()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> weaponSoundDataFinder(TEXT("/Script/Engine.DataTable'/Game/Data/DT_SoundWeapon.DT_SoundWeapon'"));
	if (weaponSoundDataFinder.Succeeded())
	{
		weaponSoundDataTable = weaponSoundDataFinder.Object;
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