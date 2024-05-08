// Fill out your copyright notice in the Description page of Project Settings.

#include "YoruPlayer/Yoru.h"
#include "YoruPlayer/YoruMoveComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include <InputMappingContext.h>

AYoru::AYoru()
{
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<USkeletalMesh> bodyMeshFinder(TEXT("/Script/Engine.SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/sk_CharM_Base.sk_CharM_Base'"));
	if (bodyMeshFinder.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(bodyMeshFinder.Object);
		GetMesh()->SetRelativeLocationAndRotation({ 0,0,-90.0 }, { 0,-90.0,0 });
	}

	mainSpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("mainSpringArm"));
	mainSpringArmComp->SetupAttachment(RootComponent);
	mainSpringArmComp->TargetArmLength = 200.0f;
	mainSpringArmComp->SocketOffset = { 0, 50, 50 };

	mainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("mainCamera"));
	mainCamera->SetupAttachment(mainSpringArmComp);

	moveComp = CreateDefaultSubobject<UYoruMoveComponent>(TEXT("moveComp"));

	static ConstructorHelpers::FObjectFinder<UInputMappingContext> iMContextFinder(TEXT("/Script/EnhancedInput.InputMappingContext'/Game/AAA/Input/IMC_Yoru.IMC_Yoru'"));

	if (iMContextFinder.Succeeded())
	{
		defaultInputMappingContext = iMContextFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> moveActionFinder(TEXT("/Script/EnhancedInput.InputAction'/Game/AAA/Input/IA_YoruMove.IA_YoruMove'"));

	if (moveActionFinder.Succeeded())
	{
		moveAction = moveActionFinder.Object;
	}
}
void AYoru::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* playerController = Cast<APlayerController>(GetController());
	if (playerController)
	{
		UEnhancedInputLocalPlayerSubsystem* subSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer());

		if (subSystem)
		{
			subSystem->AddMappingContext(defaultInputMappingContext, 0);
		}
	}
}

void AYoru::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AYoru::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* enhancedInputComponet = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	enhancedInputComponet->BindAction(moveAction, ETriggerEvent::Triggered, this, &AYoru::Move);

	moveComp->SetupPlayerInputComponent(PlayerInputComponent);

}

void AYoru::Move(const FInputActionValue& value)
{
	UE_LOG(LogTemp, Warning, TEXT("Move"));

	AddMovementInput(GetActorForwardVector(), value.Get<FVector2D>().Y);
}

