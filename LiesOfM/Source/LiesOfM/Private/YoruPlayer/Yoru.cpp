// Fill out your copyright notice in the Description page of Project Settings.

#include "YoruPlayer/Yoru.h"
#include "YoruPlayer/YoruMoveComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "YoruPlayer/YoruStatComponent.h"


AYoru::AYoru()
{
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;

	ConstructorHelpers::FObjectFinder<USkeletalMesh> bodyMeshFinder(TEXT("/Script/Engine.SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/sk_CharM_Base.sk_CharM_Base'"));
	if (bodyMeshFinder.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(bodyMeshFinder.Object);
		GetMesh()->SetRelativeLocationAndRotation({ 0,0,-90.0 }, { 0,-90.0,0 });
	}

	mainSpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("mainSpringArm"));
	mainSpringArmComp->SetupAttachment(RootComponent);
	mainSpringArmComp->TargetArmLength = 250.0f;
	mainSpringArmComp->SocketOffset = { 0, 0, 50 };
	mainSpringArmComp->bUsePawnControlRotation = true;
	mainSpringArmComp->bEnableCameraLag = true;
	mainSpringArmComp->CameraLagSpeed = 3.0f;
	mainSpringArmComp->CameraLagMaxDistance = 80.0f;

	mainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("mainCamera"));
	mainCamera->SetupAttachment(mainSpringArmComp);

	moveComp = CreateDefaultSubobject<UYoruMoveComponent>(TEXT("moveComp"));

	statComp = CreateDefaultSubobject<UYoruStatComponent>(TEXT("statComp"));

	static ConstructorHelpers::FClassFinder<UAnimInstance> animInstanceFinder(TEXT("/Script/Engine.AnimBlueprint'/Game/AAA/Blueprints/Yoru/ABP_Yoru.ABP_Yoru_C'"));

	if (animInstanceFinder.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(animInstanceFinder.Class);
	}

}
void AYoru::BeginPlay()
{
	Super::BeginPlay();

	
}

void AYoru::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AYoru::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	moveComp->SetupPlayerInputComponent(PlayerInputComponent);

}

