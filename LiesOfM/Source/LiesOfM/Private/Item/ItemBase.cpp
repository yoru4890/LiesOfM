// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/ItemBase.h"

AItemBase::AItemBase()
{
	PrimaryActorTick.bCanEverTick = false;

	itemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("itemMesh"));
	itemMesh->SetupAttachment(GetRootComponent());

	static ConstructorHelpers::FObjectFinder<UStaticMesh> itemMeshFinder(TEXT("/Script/Engine.StaticMesh'/Game/EnvironmentPack1/Meshes/Props/SM_MerchantShip_Bottle_02.SM_MerchantShip_Bottle_02'"));
	if (itemMeshFinder.Succeeded())
	{
		currentItemMesh = itemMeshFinder.Object;
	}

	itemMesh->SetStaticMesh(currentItemMesh);
}

void AItemBase::BeginPlay()
{
	Super::BeginPlay();
}

void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

