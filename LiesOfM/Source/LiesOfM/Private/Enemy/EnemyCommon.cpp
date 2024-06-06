// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyCommon.h"
#include "Enemy/EnemyCommonAIController.h"

AEnemyCommon::AEnemyCommon()
{
	weaponComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("weaponMesh"));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> weaponMeshFinder(TEXT("/Script/Engine.SkeletalMesh'/Game/InfinityBladeWeapons/Weapons/Dual_Blade/Dual_Blade_BronzeScythe/SK_Dual_Blade_BronzeScythe.SK_Dual_Blade_BronzeScythe'"));

	if (weaponMeshFinder.Succeeded())
	{
		weaponComp->SetSkeletalMesh(weaponMeshFinder.Object);
		weaponComp->SetupAttachment(GetMesh(), TEXT("RightHandSocket_Dagger"));
	}

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> meshFinder(TEXT("/Script/Engine.SkeletalMesh'/Game/AAA/Animations/Enemy/Common1/Knight_D_Pelegrini.Knight_D_Pelegrini'"));

	if (meshFinder.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(meshFinder.Object);
		GetMesh()->SetRelativeLocationAndRotation({ 0.0,0.0,-90.0 }, { 0.0,-90.0,0.0 });
	}

	static ConstructorHelpers::FClassFinder<UAnimInstance> animFinder(TEXT("/Game/AAA/Blueprints/Enemy/ABP_EnemyCommon.ABP_EnemyCommon_C"));

	if (animFinder.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(animFinder.Class);
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> attackMontageFinder(TEXT("/Script/Engine.AnimMontage'/Game/AAA/Animations/Enemy/Common1/Anim/AM_DaggerAttack.AM_DaggerAttack'"));

	if (attackMontageFinder.Succeeded())
	{
		attackMontage = attackMontageFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> hitReactionMontageFinder(TEXT("/Script/Engine.AnimMontage'/Game/AAA/Animations/Enemy/Common1/Anim/AM_HitReaction.AM_HitReaction'"));

	if (hitReactionMontageFinder.Succeeded())
	{
		hitReactionMontage = hitReactionMontageFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> hitReactionMontageFinder1(TEXT("/Script/Engine.AnimMontage'/Game/AAA/Animations/Enemy/Common1/Anim/AM_HitRight.AM_HitRight'"));

	if (hitReactionMontageFinder1.Succeeded())
	{
		hitReactionMontage1 = hitReactionMontageFinder1.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> hitReactionMontageFinder2(TEXT("/Script/Engine.AnimMontage'/Game/AAA/Animations/Enemy/Common1/Anim/AM_HitLeft.AM_HitLeft'"));

	if (hitReactionMontageFinder2.Succeeded())
	{
		hitReactionMontage2 = hitReactionMontageFinder2.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> hitReactionMontageFinder3(TEXT("/Script/Engine.AnimMontage'/Game/AAA/Animations/Enemy/Common1/Anim/AM_HitBack.AM_HitBack'"));

	if (hitReactionMontageFinder3.Succeeded())
	{
		hitReactionMontage3 = hitReactionMontageFinder3.Object;
	}
}

void AEnemyCommon::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemyCommon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemyCommon::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AEnemyCommon::ReceiveDamage(float damageAmount, AActor* attackingActor, const FHitResult& hitResult)
{
	GetMesh()->GetAnimInstance()->Montage_Play(hitReactionMontage);

	FVector actorDirection{ GetActorRotation().Vector().GetSafeNormal2D() };
	FVector actorRightDirection{ (FRotationMatrix(GetActorRotation()).GetScaledAxis(EAxis::Y)).GetSafeNormal2D() };
	FVector hitDirection{ (hitResult.ImpactPoint - GetActorLocation()).GetSafeNormal2D() };
	double rightDotResult{ FVector::DotProduct(actorRightDirection, hitDirection) };
	double angle{ FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(actorDirection, hitDirection))) };
	if (rightDotResult < 0)
	{
		angle *= -1;
	}

	if (angle <= 45.0f && angle >= -45.0f)
	{
		GetMesh()->GetAnimInstance()->Montage_Play(hitReactionMontage);
	}
	else if (angle > 45.0f && angle <= 135.0f)
	{
		GetMesh()->GetAnimInstance()->Montage_Play(hitReactionMontage1);
	}
	else if (angle < -45.0f && angle >= -135.0f)
	{
		GetMesh()->GetAnimInstance()->Montage_Play(hitReactionMontage2);
	}
	else
	{
		GetMesh()->GetAnimInstance()->Montage_Play(hitReactionMontage3);
	}
}

void AEnemyCommon::CommonAttack()
{
	if (!(GetMesh()->GetAnimInstance()->Montage_IsPlaying(attackMontage)))
	{
		GetMesh()->GetAnimInstance()->Montage_Play(attackMontage);
	}
}
