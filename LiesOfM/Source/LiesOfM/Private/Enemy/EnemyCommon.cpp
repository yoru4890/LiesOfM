// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyCommon.h"
#include "Enemy/EnemyCommonAIController.h"
#include "Weapon/WeaponBase.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Collision/CollisionChannel.h"
#include "YoruPlayer/Yoru.h"

AEnemyCommon::AEnemyCommon()
{
	daggerWeapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("weaponMesh"));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> weaponMeshFinder(TEXT("/Script/Engine.SkeletalMesh'/Game/InfinityBladeWeapons/Weapons/Dual_Blade/Dual_Blade_BronzeScythe/SK_Dual_Blade_BronzeScythe.SK_Dual_Blade_BronzeScythe'"));

	if (weaponMeshFinder.Succeeded())
	{
		daggerWeapon->SetSkeletalMesh(weaponMeshFinder.Object);
		daggerWeapon->SetupAttachment(GetMesh(), TEXT("RightHandSocket_Dagger"));
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

	switch (enemyWeapon)
	{
	case EEnemyCommonWeapon::None:
		break;
	case EEnemyCommonWeapon::Dagger:
		break;
	case EEnemyCommonWeapon::Bow:
		daggerWeapon->SetVisibility(false);
		SpawnBow();
		break;
	case EEnemyCommonWeapon::Size:
		break;
	default:
		break;
	}
}

void AEnemyCommon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (attackElapsedTime >= attackCooltime)
	{
		attackElapsedTime = 0;
		OnAttackFinished.ExecuteIfBound();
	}
	else if(attackElapsedTime)
	{
		attackElapsedTime += DeltaTime;
	}
}

void AEnemyCommon::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AEnemyCommon::ReceiveDamage(float damageAmount, AActor* attackingActor, const FHitResult& hitResult)
{
	currentEnemyState = EEnemyState::BeingAttacked;
	OnBeingAttacked.ExecuteIfBound();

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
	currentEnemyState = EEnemyState::Attacking;

	if (!(GetMesh()->GetAnimInstance()->Montage_IsPlaying(attackMontage)))
	{
		GetMesh()->GetAnimInstance()->Montage_Play(attackMontage);
	}
}

void AEnemyCommon::SpawnBow()
{
	UObject* spawnActor = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Script/Engine.Blueprint'/Game/AAA/Blueprints/Weapon/BP_Bow.BP_Bow'")));

	UBlueprint* generatedBP = Cast<UBlueprint>(spawnActor);

	if (!spawnActor)
	{
		return;
	}

	UClass* spawnClass = spawnActor->StaticClass();

	if (!spawnClass)
	{
		return;
	}

	FTransform tempTransform{ GetMesh()->GetSocketTransform(TEXT("LeftHandSocket_Bow")) };

	FActorSpawnParameters spawnParams;
	spawnParams.Owner = this;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	bow = GetWorld()->SpawnActor<AWeaponBase>(generatedBP->GeneratedClass, tempTransform, spawnParams);

	bow->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("LeftHandSocket_Bow"));
}

void AEnemyCommon::NotifyAttackEnd()
{
	OnAttackFinished.ExecuteIfBound();
}

void AEnemyCommon::TriggerTrace()
{
	hitActors.Reset();
	GetWorld()->GetTimerManager().SetTimer(lineTraceTimeHandle, this, &AEnemyCommon::ApplyTrace, 0.01, true);
}

void AEnemyCommon::ApplyTrace()
{
	FVector start{ daggerWeapon->GetSocketLocation(TEXT("StartPoint")) };
	FVector end{ daggerWeapon->GetSocketLocation(TEXT("EndPoint")) };
	TArray<AActor*> ignoreActors;
	TArray<FHitResult> outHits;
	ignoreActors.Add(this);
	bool isHit = UKismetSystemLibrary::SphereTraceMulti(GetWorld(), start, end, 15.0, TCHANNEL_ENEMYDAMAGE, false, ignoreActors, EDrawDebugTrace::None, outHits, true);
	if (isHit)
	{
		for (const auto& hitResult : outHits)
		{
			if (hitResult.GetActor()->GetClass()->IsChildOf<AYoru>() && !hitActors.Contains(hitResult.GetActor()))
			{
				hitActors.Add(hitResult.GetActor());
				Cast<AYoru>(hitResult.GetActor())->ReceiveDamage(CaculateDamage(), this, hitResult);
			}
		}

	}
}

void AEnemyCommon::StopTrace()
{
	GetWorld()->GetTimerManager().ClearTimer(lineTraceTimeHandle);
}

float AEnemyCommon::CaculateDamage()
{
	float attackDamage{};
	switch (enemyWeapon)
	{
		case EEnemyCommonWeapon::Dagger:
			attackDamage = 20.0f;
			break;
		case EEnemyCommonWeapon::Bow:
			attackDamage = 15.0f;
			break;
		default:
			break;
	}
	return attackDamage;
}

float AEnemyCommon::GetAIPatrolRadius()
{
	return 800.0f;
}

float AEnemyCommon::GetAIDetectRange()
{
	return 600.0f;
}

float AEnemyCommon::GetAIAttackRange()
{
	return attackRange;
}

float AEnemyCommon::GetAIRange()
{
	return attackRange - 50.0f;
}

float AEnemyCommon::GetAITurnSpeed()
{
	return 4.0f;
}

void AEnemyCommon::SetAIAttackDelegate(const FCommonAIAttackFinished& InOnAttackFinished)
{
	OnAttackFinished = InOnAttackFinished;
}

void AEnemyCommon::SetAIBeingAttackedDelegate(const FCommonAIBeingAttacked& InOnBeingAttacked)
{
	OnBeingAttacked = InOnBeingAttacked;
}

bool AEnemyCommon::AttackByAI()
{
	if (!attackElapsedTime)
	{
		CommonAttack();
		attackElapsedTime += GetWorld()->GetDeltaSeconds();
		return true;
	}
	else
	{
		return false;
	}
}

bool AEnemyCommon::NoTurn()
{
	if (enemyWeapon == EEnemyCommonWeapon::Dagger && GetMesh()->GetAnimInstance()->Montage_IsPlaying(attackMontage))
	{
		return true;
	}
	return false;
}
