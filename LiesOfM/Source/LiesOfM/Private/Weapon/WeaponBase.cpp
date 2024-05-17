// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/WeaponBase.h"

AWeaponBase::AWeaponBase()
{
	PrimaryActorTick.bCanEverTick = false;

	weaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("weaponMesh"));
	weaponMesh->SetupAttachment(GetRootComponent());

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> weaponMeshFinder(TEXT("/Script/Engine.SkeletalMesh'/Game/InfinityBladeWeapons/Weapons/Blade/Swords/Blade_BlackKnight/SK_Blade_BlackKnight.SK_Blade_BlackKnight'"));
	if (weaponMeshFinder.Succeeded())
	{
		currentWeaponMesh = weaponMeshFinder.Object;
	}

	weaponMesh->SetSkeletalMesh(currentWeaponMesh);

	static ConstructorHelpers::FObjectFinder<UDataTable> attackAnimDataFinder(TEXT("/Script/Engine.DataTable'/Game/AAA/Blueprints/Weapon/DT_Weapon.DT_Weapon'"));
	if (attackAnimDataFinder.Succeeded())
	{
		attackAnimations = attackAnimDataFinder.Object;
	}
}

void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


