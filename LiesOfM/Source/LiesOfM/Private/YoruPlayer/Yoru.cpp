// Fill out your copyright notice in the Description page of Project Settings.

#include "YoruPlayer/Yoru.h"
#include "YoruPlayer/YoruMoveComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "YoruPlayer/YoruStatComponent.h"
#include "YoruPlayer/YoruWidgetComponent.h"
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include <InputMappingContext.h>
#include "YoruPlayer/YoruAttackComponent.h"
#include "YoruPlayer/YoruDefenceComponent.h"
#include "TOMGameInstance.h"
#include "YoruPlayer/YoruLockonComponent.h"
#include "Components/WidgetComponent.h"

AYoru::AYoru()
{
	ConstructorHelpers::FObjectFinder<USkeletalMesh> bodyMeshFinder(TEXT("/Script/Engine.SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/sk_CharM_Base.sk_CharM_Base'"));
	if (bodyMeshFinder.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(bodyMeshFinder.Object);
		GetMesh()->SetRelativeLocationAndRotation({ 0,0,-90.0 }, { 0,-90.0,0 });
	}

	mainSpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("mainSpringArm"));
	mainSpringArmComp->SetupAttachment(RootComponent);
	mainSpringArmComp->TargetArmLength = 280.0f;
	mainSpringArmComp->SocketOffset = { 0, 0, 50 };
	mainSpringArmComp->bUsePawnControlRotation = true;
	mainSpringArmComp->bEnableCameraLag = true;
	mainSpringArmComp->CameraLagSpeed = 3.0f;
	mainSpringArmComp->CameraLagMaxDistance = 80.0f;

	mainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("mainCamera"));
	mainCamera->SetupAttachment(mainSpringArmComp);

	//rightWeapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("rightWeapon"));
	//rightWeapon->SetupAttachment(GetMesh(), TEXT("hand_rSocket_GreatSword"));

	//ConstructorHelpers::FObjectFinder<USkeletalMesh> greatSwordFinder(TEXT("/Script/Engine.SkeletalMesh'/Game/InfinityBladeWeapons/Weapons/Blade/Swords/Blade_BlackKnight/SK_Blade_BlackKnight.SK_Blade_BlackKnight'"));
	//if (greatSwordFinder.Succeeded())
	//{
	//	rightWeapon->SetSkeletalMesh(greatSwordFinder.Object);
	//}

	statComp = CreateDefaultSubobject<UYoruStatComponent>(TEXT("statComp"));
	moveComp = CreateDefaultSubobject<UYoruMoveComponent>(TEXT("moveComp"));
	widgetComp = CreateDefaultSubobject<UYoruWidgetComponent>(TEXT("widgetComp"));
	attackComp = CreateDefaultSubobject<UYoruAttackComponent>(TEXT("attackComp"));
	defenceComp = CreateDefaultSubobject<UYoruDefenceComponent>(TEXT("defenceComp"));
	lockonComp = CreateDefaultSubobject<UYoruLockonComponent>(TEXT("lockonComp"));

	lockonWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("lockonWidget"));
	lockonWidget->SetupAttachment(RootComponent);
	lockonWidget->SetWidgetSpace(EWidgetSpace::Screen);
	lockonWidget->SetDrawSize({ 15,15 });
	lockonWidget->SetVisibility(false);

	static ConstructorHelpers::FClassFinder<UAnimInstance> animInstanceFinder(TEXT("/Game/AAA/Blueprints/Yoru/ABP_Yoru.ABP_Yoru_C"));

	if (animInstanceFinder.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(animInstanceFinder.Class);
	}

	static ConstructorHelpers::FObjectFinder<UInputMappingContext> iMContextFinder(TEXT("/Script/EnhancedInput.InputMappingContext'/Game/AAA/Input/IMC_Yoru.IMC_Yoru'"));

	if (iMContextFinder.Succeeded())
	{
		defaultInputMappingContext = iMContextFinder.Object;
	}

	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->MaxWalkSpeed = statComp->jogSpeed;
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
	
	singleGameInstance = Cast<UTOMGameInstance>(GetGameInstance());
	dataTableRowNames = singleGameInstance->playerDataTable->GetRowNames();
}

void AYoru::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AYoru::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* enhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	moveComp->SetupPlayerInputComponent(enhancedInputComponent);
	attackComp->SetupPlayerInputComponent(enhancedInputComponent);
	lockonComp->SetupPlayerInputComponent(enhancedInputComponent);
	defenceComp->SetupPlayerInputComponent(enhancedInputComponent);
}

void AYoru::SetPlayerState(const TEnumAsByte<EPlayerState>& state)
{
	currentPlayerState = state;
}

void AYoru::ReceiveDamage(float damageAmount, AActor* attackingActor, const FHitResult& hitResult)
{
	if (GetPlayerState() == EPlayerState::Blocking)
	{
		
	}
	else
	{
		if (defenceComp->CheckParrying())
		{
			UE_LOG(LogTemp, Warning, TEXT("Parrying"));
		}
		else
		{
			defenceComp->HitReaction(damageAmount, attackingActor, hitResult);
		}
	}

}

void AYoru::SetIsLockon(bool lockon)
{
	isLockon = lockon;
	ChangeCamera(lockon);
}

void AYoru::ChangeCamera(bool isLockonMove)
{
	if (isLockonMove)
	{
		bUseControllerRotationYaw = true;
		GetCharacterMovement()->bOrientRotationToMovement = false;
	}
	else
	{
		bUseControllerRotationYaw = false;
		GetCharacterMovement()->bOrientRotationToMovement = true;
	}
}
