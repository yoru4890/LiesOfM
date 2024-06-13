// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyBoss.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Enemy/EnemyBossAIController.h"
#include "Kismet/GameplayStatics.h"

AEnemyBoss::AEnemyBoss()
{
	weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("weaponMesh"));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> meshFinder(TEXT("/Script/Engine.SkeletalMesh'/Game/AAA/Animations/Enemy/Boss1/Uriel_A_Plotexia.Uriel_A_Plotexia'"));

	if (meshFinder.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(meshFinder.Object);
		GetMesh()->SetRelativeLocationAndRotation({ 0.0,0.0,-90.0 }, { 0.0,-90.0,0.0 });
	}

	static ConstructorHelpers::FClassFinder<UAnimInstance> animFinder(TEXT("/Script/Engine.AnimBlueprint'/Game/AAA/Blueprints/Enemy/Boss/ABP_EnemyBoss.ABP_EnemyBoss_C'"));

	if (animFinder.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(animFinder.Class);
	}

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> weaponMeshFinder(TEXT("/Script/Engine.SkeletalMesh'/Game/InfinityBladeWeapons/Weapons/Blade/Axes/Blade_GreatBlade/SK_Blade_GreatBlade.SK_Blade_GreatBlade'"));

	if (weaponMeshFinder.Succeeded())
	{
		weapon->SetSkeletalMesh(weaponMeshFinder.Object);
		weapon->SetupAttachment(GetMesh(), TEXT("RightHandSocket_Weapon"));
	}
}

void AEnemyBoss::BeginPlay()
{
	Super::BeginPlay();

	maxGroggy = 250.0f;
}

void AEnemyBoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	auto RotateTemp = (player->GetActorLocation() - GetActorLocation()).Rotation();
	RotateTemp.Pitch = 0;

	SetActorRotation(RotateTemp);
}

void AEnemyBoss::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AEnemyBoss::ReceiveDamage(float damageAmount, AActor* attackingActor, const FHitResult& hitResult)
{
	Super::ReceiveDamage(damageAmount, attackingActor, hitResult);
}

void AEnemyBoss::ReceiveGroggyDamage(float damageAmount, AActor* attackingActor)
{
	Super::ReceiveGroggyDamage(damageAmount, attackingActor);
}

bool AEnemyBoss::CanGrabAttacked()
{
	Super::CanGrabAttacked();
	return false;
}

void AEnemyBoss::GrabAttacked(bool isFront)
{
	Super::GrabAttacked(isFront);
}

void AEnemyBoss::Groggy()
{
	Super::Groggy();
}

void AEnemyBoss::CaculateDamage(float damage)
{
	Super::CaculateDamage(damage);
}

void AEnemyBoss::ChangePhase()
{
}

void AEnemyBoss::Attack()
{
}

void AEnemyBoss::CounterAttack()
{
}

void AEnemyBoss::RushAttack()
{
}

void AEnemyBoss::JumpAttack()
{
}

void AEnemyBoss::meleeAttack1()
{
}

void AEnemyBoss::meleeAttack2()
{
}

void AEnemyBoss::meleeAttack3()
{
}

void AEnemyBoss::TriggerTrace()
{
}

void AEnemyBoss::ApplyTrace()
{
}

void AEnemyBoss::StopTrace()
{
}

void AEnemyBoss::ShowRedAttack()
{
}

void AEnemyBoss::HiddenRedAttack()
{
}

float AEnemyBoss::GetAIAttackMeleeRange()
{
	return 300.0f;
}

float AEnemyBoss::GetAIAttackLongRange()
{
	return 600.0f;
}

void AEnemyBoss::SetAIMoveFinishedDelegate(const FAIRandomMoveFinished& InOnRandomMoveFinished)
{
	OnRandomMoveFinished = InOnRandomMoveFinished;
}

void AEnemyBoss::SetAIAttackFinishedDelegate(const FAIAttackFinished& InOnAttackFinished)
{
	OnAttackFinished = InOnAttackFinished;
}

void AEnemyBoss::RandomMoveByAI()
{
	FVector Direction = FMath::VRand().GetSafeNormal2D();
	FTransform Temp(GetActorRotation(), GetActorLocation() + Direction);

	Cast<AEnemyBossAIController>(GetController())->MoveToLocation(GetActorLocation() + Direction * 500);

	FTimerHandle randomMoveTimer{};
	GetWorld()->GetTimerManager().SetTimer(randomMoveTimer, [this]()
		{
			StopRandomMove();
		}, 0.01f, false, 2.0f);
}

bool AEnemyBoss::AttackByAI()
{
	return false;
}

void AEnemyBoss::StopRandomMove()
{
	OnRandomMoveFinished.ExecuteIfBound();
}
