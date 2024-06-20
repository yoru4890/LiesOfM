// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyBoss.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Enemy/EnemyBossAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Collision/CollisionChannel.h"
#include "YoruPlayer/Yoru.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Enemy/BossWidget.h"
#include "Enemy/EnemyBaseMovement.h"
#include "Animation/AnimMontage.h"
#include "Particles/ParticleSystem.h"

AEnemyBoss::AEnemyBoss()
{
	weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("weaponMesh"));
	wing = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("wing"));
	wing->SetupAttachment(GetMesh(), "Wing");

	redAttackBody = CreateDefaultSubobject<UNiagaraComponent>(TEXT("redAttackBody"));
	redAttackBody->SetupAttachment(GetMesh());
	redAttackWeapon = CreateDefaultSubobject<UNiagaraComponent>(TEXT("redAttackWeapon"));
	redAttackWeapon->SetupAttachment(weapon);

	yellowBody = CreateDefaultSubobject<UNiagaraComponent>(TEXT("yellowBdoy"));
	yellowBody->SetupAttachment(GetMesh());
	yellowWeapon = CreateDefaultSubobject<UNiagaraComponent>(TEXT("yellowWeapon"));
	yellowWeapon->SetupAttachment(weapon);

	widgetComp = CreateDefaultSubobject<UBossWidget>(TEXT("widgetComp"));
	moveComp = CreateDefaultSubobject<UEnemyBaseMovement>(TEXT("moveComp"));

	InitContents();

}

void AEnemyBoss::InitContents()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> meshFinder(TEXT("/Script/Engine.SkeletalMesh'/Game/AAA/Animations/Enemy/Boss1/Uriel_A_Plotexia.Uriel_A_Plotexia'"));

	if (meshFinder.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(meshFinder.Object);
		GetMesh()->SetRelativeLocationAndRotation({ 0.0,0.0,-90.0 }, { 0.0,-90.0,0.0 });
	}

	static ConstructorHelpers::FObjectFinder<UStaticMesh> wingMeshFinder(TEXT("/Script/Engine.StaticMesh'/Game/AAA/StaticMesh/Fracture/SM_AngelStatue_GeometryCollection_SM_1_.SM_AngelStatue_GeometryCollection_SM_1_'"));

	if (wingMeshFinder.Succeeded())
	{
		wing->SetStaticMesh(wingMeshFinder.Object);
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

	static ConstructorHelpers::FObjectFinder<UAnimMontage> meleeAttack1MontageFinder(TEXT("/Script/Engine.AnimMontage'/Game/AAA/Animations/Enemy/Boss1/Anim/AM_MeleeAttack1.AM_MeleeAttack1'"));

	if (meleeAttack1MontageFinder.Succeeded())
	{
		meleeAttack1Montage = meleeAttack1MontageFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> meleeAttack2MontageFinder(TEXT("/Script/Engine.AnimMontage'/Game/AAA/Animations/Enemy/Boss1/Anim/AM_MeleeAttack2.AM_MeleeAttack2'"));

	if (meleeAttack2MontageFinder.Succeeded())
	{
		meleeAttack2Montage = meleeAttack2MontageFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> meleeAttack3MontageFinder(TEXT("/Script/Engine.AnimMontage'/Game/AAA/Animations/Enemy/Boss1/Anim/AM_MeleeAttack3.AM_MeleeAttack3'"));

	if (meleeAttack3MontageFinder.Succeeded())
	{
		meleeAttack3Montage = meleeAttack3MontageFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> rushAttackMontageFinder(TEXT("/Script/Engine.AnimMontage'/Game/AAA/Animations/Enemy/Boss1/Anim/AM_RushAttack.AM_RushAttack'"));

	if (rushAttackMontageFinder.Succeeded())
	{
		rushAttackMontage = rushAttackMontageFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> jumpAttackMontageFinder(TEXT("/Script/Engine.AnimMontage'/Game/AAA/Animations/Enemy/Boss1/Anim/AM_JumpAttack.AM_JumpAttack'"));

	if (jumpAttackMontageFinder.Succeeded())
	{
		jumpAttackMontage = jumpAttackMontageFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> counterBlockMontageFinder(TEXT("/Script/Engine.AnimMontage'/Game/AAA/Animations/Enemy/Boss1/Anim/AM_CounterBlock.AM_CounterBlock'"));

	if (counterBlockMontageFinder.Succeeded())
	{
		counterBlockMontage = counterBlockMontageFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> counterAttackMontageFinder(TEXT("/Script/Engine.AnimMontage'/Game/AAA/Animations/Enemy/Boss1/Anim/AM_CounterAttack.AM_CounterAttack'"));

	if (counterAttackMontageFinder.Succeeded())
	{
		counterAttackMontage = counterAttackMontageFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> changePhaseMontageFinder(TEXT("/Script/Engine.AnimMontage'/Game/AAA/Animations/Enemy/Boss1/Anim/AM_ChangePhase.AM_ChangePhase'"));

	if (changePhaseMontageFinder.Succeeded())
	{
		changePhaseMontage = changePhaseMontageFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> groggyMontageFinder(TEXT("/Script/Engine.AnimMontage'/Game/AAA/Animations/Enemy/Boss1/Anim/GrabAttacked/AM_Groggy.AM_Groggy'"));

	if (groggyMontageFinder.Succeeded())
	{
		groggyMontage = groggyMontageFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> grabAttacked1MontageFinder(TEXT("/Script/Engine.AnimMontage'/Game/AAA/Animations/Enemy/Boss1/Anim/GrabAttacked/AM_GrabAttacked_Front.AM_GrabAttacked_Front'"));

	if (grabAttacked1MontageFinder.Succeeded())
	{
		grabAttackedFrontMontage = grabAttacked1MontageFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> grabAttacked2MontageFinder(TEXT("/Script/Engine.AnimMontage'/Game/AAA/Animations/Enemy/Boss1/Anim/GrabAttacked/AM_GrabAttacked_Back.AM_GrabAttacked_Back'"));

	if (grabAttacked2MontageFinder.Succeeded())
	{
		grabAttackedBackMontage = grabAttacked2MontageFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<USoundBase> blockingSoundFinder(TEXT("/Script/Engine.SoundWave'/Game/AAA/Audio/GreatSword/SW_GreatSwordBlocking_1.SW_GreatSwordBlocking_1'"));

	if (blockingSoundFinder.Succeeded())
	{
		blockingSound = blockingSoundFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UParticleSystem> lightningEffectFinder(TEXT("/Script/Engine.ParticleSystem'/Game/FXVarietyPack/Particles/P_ky_lightning3.P_ky_lightning3'"));

	if (lightningEffectFinder.Succeeded())
	{
		lightningEffect = lightningEffectFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UParticleSystem> lightningGroundEffectFinder(TEXT("/Script/Engine.ParticleSystem'/Game/AAA/Effect/Cascade/P_Lightning_Ground.P_Lightning_Ground'"));

	if (lightningGroundEffectFinder.Succeeded())
	{
		lightningGroundEffect = lightningGroundEffectFinder.Object;
	}
}

void AEnemyBoss::BeginPlay()
{
	Super::BeginPlay();

	maxGroggy = 250.0f;
	currentHealth = maxHealth;
	BossAIController = Cast<AEnemyBossAIController>(GetController());

	Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	bloodFX = LoadObject<UNiagaraSystem>(nullptr, TEXT("/Script/Niagara.NiagaraSystem'/Game/AAA/Effect/Niagara/NS_Blood.NS_Blood'"));

	blockingFX = LoadObject<UNiagaraSystem>(nullptr, TEXT("/Script/Niagara.NiagaraSystem'/Game/AAA/Effect/Niagara/NS_Blocking.NS_Blocking'"));

	yoru = Cast<AYoru>(Player);
}

void AEnemyBoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (isLockon)
	{
		auto RotateTemp = (Player->GetActorLocation() - GetActorLocation()).Rotation();
		RotateTemp.Pitch = 0;

		SetActorRotation(FMath::RInterpTo(GetActorRotation(), RotateTemp, DeltaTime, turnSpeed));
	}

	if (yoru->isDie)
	{
		BossAIController->StopAI();
	}

	playerDistance = FVector::Distance(GetActorLocation(), Player->GetActorLocation());
}

void AEnemyBoss::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AEnemyBoss::ReceiveDamage(float damageAmount, AActor* attackingActor, const FHitResult& hitResult, bool isRedAttack)
{
	if (!isHittable) return;

	if (isCounter)
	{
		isCounter = false;
		FVector tempPoint = hitResult.ImpactPoint;
		tempPoint.Z += 50.0f;
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), blockingFX, tempPoint);
		UGameplayStatics::PlaySoundAtLocation(this, blockingSound, tempPoint, 1.0f, 1.0f, 0.1f);
		GetMesh()->GetAnimInstance()->Montage_Play(counterAttackMontage);
		return;
	}

	if (isChanging)
	{
		damageAmount /= 10;
	}

	CaculateDamage(damageAmount);

	FVector actorDirection{ GetActorRotation().Vector().GetSafeNormal2D() };
	FVector actorRightDirection{ (FRotationMatrix(GetActorRotation()).GetScaledAxis(EAxis::Y)).GetSafeNormal2D() };
	FVector hitDirection{ (hitResult.ImpactPoint - GetActorLocation()).GetSafeNormal2D() };
	double rightDotResult{ FVector::DotProduct(actorRightDirection, hitDirection) };
	double angle{ FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(actorDirection, hitDirection))) };
	if (rightDotResult < 0)
	{
		angle *= -1;
	}

	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), bloodFX, hitResult.ImpactPoint);
}

void AEnemyBoss::ReceiveGroggyDamage(float damageAmount, AActor* attackingActor)
{
	Super::ReceiveGroggyDamage(damageAmount, attackingActor);

	if (bRedAttack)
	{
		damageAmount *= 4;
	}

	currentGroggy += damageAmount;
	if (currentGroggy >= maxGroggy)
	{
		currentGroggy = maxGroggy;
		Groggy();
	}
}

bool AEnemyBoss::CanGrabAttacked()
{
	Super::CanGrabAttacked();
	return false;
}

void AEnemyBoss::GrabAttacked(bool isFront)
{
	Super::GrabAttacked(isFront);

	currentEnemyState = EEnemyState::GrabAttacked;

	if (isFront)
	{
		GetMesh()->GetAnimInstance()->Montage_Play(grabAttackedFrontMontage);
	}
	else
	{
		GetMesh()->GetAnimInstance()->Montage_Play(grabAttackedBackMontage);
	}
}

void AEnemyBoss::Groggy()
{
	Super::Groggy();
	moveComp->SetSubBackMoveValue(1);
	currentEnemyState = EEnemyState::Groggy;
	HiddenRedAttack();
	HiddenYellowMode();
	moveComp->ChaseMoveToggle(false);
	currentGroggy = 0;
	GetMesh()->GetAnimInstance()->Montage_Play(groggyMontage);
}

void AEnemyBoss::CaculateDamage(float damage)
{
	Super::CaculateDamage(damage);

	currentHealth -= damage;
	if (currentHealth <= 0)
	{
		TriggerWidget(damage + currentHealth);
		Dead();
	}
	else
	{
		TriggerWidget(damage);
	}
}

void AEnemyBoss::ChangeLockonPlayer(bool InisLockon)
{
	isLockon = InisLockon;
}

void AEnemyBoss::NotifyAttackEnd()
{
	OnAttackFinished.ExecuteIfBound();
	ChangeLockonPlayer(true);
}

void AEnemyBoss::ChangePhase()
{
	phase++;
	isChanging = true;

	SummonLightning(Player->GetActorLocation() - (0,0,65.0f));

	if (!(GetMesh()->GetAnimInstance()->IsAnyMontagePlaying()))
	{
		GetMesh()->GetAnimInstance()->Montage_Play(changePhaseMontage);
	}
}

void AEnemyBoss::Attack()
{
	if (!phase && GetHPRatio() <= 0.5)
	{
		ChangePhase();
		return;
	}

	enum EAttack
	{
		JUMPATTACK,
		RUSHATTACK,
		MELEEATTACK1,
		MELEEATTACK2,
		MELEEATTACK3,
		COUNTER,

		Size
	};

	EAttack randomAttackNum{};
	int32 randomNum{ -1 };
	do
	{
		if (playerDistance <= 300.0f)
		{
			randomNum = FMath::RandHelper(6);
		}
		else if (playerDistance <= 450.0f)
		{
			randomNum = FMath::RandHelper(2);
		}
	} while (randomNum == preAttack);

	if (playerDistance > 450.0f)
	{
		if (phase == 1)
		{
			randomNum = FMath::RandHelper(2);
		}
		else
		{
			randomNum = 0;
		}
	}
	preAttack = randomNum;

	randomAttackNum = static_cast<EAttack>(randomNum);

	switch (randomAttackNum)
	{
	case JUMPATTACK:
		JumpAttack();
		break;
	case RUSHATTACK:
		RushAttack();
		break;
	case MELEEATTACK1:
		MeleeAttack1();
		break;
	case MELEEATTACK2:
		MeleeAttack2();
		break;
	case MELEEATTACK3:
		MeleeAttack3();
		break;
	case COUNTER:
		Counter();
		break;
	case Size:
		break;
	default:
		break;
	}
}

void AEnemyBoss::CounterAttack()
{
	if (!(GetMesh()->GetAnimInstance()->IsAnyMontagePlaying()))
	{
		GetMesh()->GetAnimInstance()->Montage_Play(counterAttackMontage);
	}
}

void AEnemyBoss::RushAttack()
{

	if (!(GetMesh()->GetAnimInstance()->IsAnyMontagePlaying()))
	{
		GetMesh()->GetAnimInstance()->Montage_Play(rushAttackMontage);
	}


}

void AEnemyBoss::JumpAttack()
{

	if (!(GetMesh()->GetAnimInstance()->IsAnyMontagePlaying()))
	{
		GetMesh()->GetAnimInstance()->Montage_Play(jumpAttackMontage);
	}


}

void AEnemyBoss::MeleeAttack1()
{
	if (!(GetMesh()->GetAnimInstance()->IsAnyMontagePlaying()))
	{
		GetMesh()->GetAnimInstance()->Montage_Play(meleeAttack1Montage);
	}
}

void AEnemyBoss::MeleeAttack2()
{

	moveComp->SetSubBackMoveValue(0.2f);

	if (!(GetMesh()->GetAnimInstance()->IsAnyMontagePlaying()))
	{
		GetMesh()->GetAnimInstance()->Montage_Play(meleeAttack2Montage);
	}


}

void AEnemyBoss::MeleeAttack3()
{
	if (!(GetMesh()->GetAnimInstance()->IsAnyMontagePlaying()))
	{
		GetMesh()->GetAnimInstance()->Montage_Play(meleeAttack3Montage);
	}
}

void AEnemyBoss::Counter()
{
	if (!(GetMesh()->GetAnimInstance()->IsAnyMontagePlaying()))
	{
		GetMesh()->GetAnimInstance()->Montage_Play(counterBlockMontage);
	}
}

void AEnemyBoss::TriggerTrace()
{
	hitActors.Reset();
	GetWorld()->GetTimerManager().SetTimer(lineTraceTimeHandle, this, &AEnemyBoss::ApplyTrace, 0.01, true);
}

void AEnemyBoss::ApplyTrace()
{
	FVector start{ };
	FVector end{ };
	float radius{ 80.0f };

	start = weapon->GetSocketLocation(TEXT("StartPoint"));
	end = weapon->GetSocketLocation(TEXT("EndPoint"));

	TArray<AActor*> ignoreActors;
	TArray<FHitResult> outHits;
	ignoreActors.Add(this);
	bool isHit = UKismetSystemLibrary::SphereTraceMulti(GetWorld(), start, end, radius, TCHANNEL_ENEMYDAMAGE, false, ignoreActors, EDrawDebugTrace::None, outHits, true);
	if (isHit)
	{
		for (const auto& hitResult : outHits)
		{
			if (hitResult.GetActor()->GetClass()->IsChildOf<AYoru>() && !hitActors.Contains(hitResult.GetActor()))
			{
				hitActors.Add(hitResult.GetActor());
				Cast<AYoru>(hitResult.GetActor())->ReceiveDamage(resultDamage, this, hitResult, bRedAttack);
			}
		}

	}
}

void AEnemyBoss::StopTrace()
{
	GetWorld()->GetTimerManager().ClearTimer(lineTraceTimeHandle);
}

void AEnemyBoss::ShowRedAttack()
{
	bRedAttack = true;
	redAttackBody->SetVisibility(true);
	redAttackWeapon->SetVisibility(true);
	ChangeLockonPlayer(true);
	turnSpeed = redAttackTurnSpeed;
}

void AEnemyBoss::HiddenRedAttack()
{
	bRedAttack = false;
	redAttackBody->SetVisibility(false);
	redAttackWeapon->SetVisibility(false);
	ChangeLockonPlayer(false);
	turnSpeed = normalTurnSpeed;
}

void AEnemyBoss::ChangeDamage(float damage)
{
	resultDamage = damage;
}

void AEnemyBoss::TriggerWidget(float damage)
{
	totalDamage += damage;
	widgetComp->UpdateHP();
	widgetComp->UpdateDamageText(totalDamage);
}

void AEnemyBoss::RemoveWidget()
{
	widgetComp->HiddenWidget();
}

void AEnemyBoss::Dead()
{
	GetMesh()->GetAnimInstance()->StopAllMontages(0.1f);
	HiddenRedAttack();
	isDead = true;
	AEnemyBossAIController* temp = Cast<AEnemyBossAIController>(GetController());
	if (temp)
	{
		temp->StopAI();
	}
	UPrimitiveComponent* PrimitiveComponent = Cast<UPrimitiveComponent>(RootComponent);
	PrimitiveComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	weapon->SetVisibility(false);
}

void AEnemyBoss::PlayAnimBossDieText()
{
	widgetComp->PlayAnimationBossDie();
}

void AEnemyBoss::EndChange()
{
	isChanging = false;
}

void AEnemyBoss::EndCounter()
{
	isCounter = false;
}

void AEnemyBoss::ChangeRushAttack()
{
	if (phase == 1)
	{
		GetMesh()->GetAnimInstance()->Montage_Play(rushAttackMontage);
	}
}

void AEnemyBoss::SummonLightning(const FVector& location)
{
	lightningLoc = location;
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), lightningGroundEffect, location);

	FTimerHandle tempEffectTH{};
	GetWorld()->GetTimerManager().SetTimer(tempEffectTH, [this]()
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), lightningEffect, lightningLoc);
		}, 0.1f, false, 0.7);

	FTimerHandle tempDamageTH{};
	GetWorld()->GetTimerManager().SetTimer(tempDamageTH, this, &AEnemyBoss::LightningAttack, 0.1f, false, 0.8);
	
}

void AEnemyBoss::ShowWing()
{
	wing->SetVisibility(true);
}

void AEnemyBoss::HiddenWing()
{
	wing->SetVisibility(false);
}

void AEnemyBoss::ShowYellowMode()
{
	yellowBody->SetVisibility(true);
	yellowWeapon->SetVisibility(true);
}

void AEnemyBoss::HiddenYellowMode()
{
	yellowBody->SetVisibility(false);
	yellowWeapon->SetVisibility(false);
}

void AEnemyBoss::LightningAttack()
{
	FVector start{ lightningLoc };
	FVector end{ lightningLoc };
	float radius{ 120.0f };
	hitActors.Reset();
	TArray<AActor*> ignoreActors;
	TArray<FHitResult> outHits;
	ignoreActors.Add(this);
	bool isHit = UKismetSystemLibrary::SphereTraceMulti(GetWorld(), start, end, radius, TCHANNEL_ENEMYDAMAGE, false, ignoreActors, EDrawDebugTrace::None, outHits, true);
	if (isHit)
	{
		for (const auto& hitResult : outHits)
		{
			if (hitResult.GetActor()->GetClass()->IsChildOf<AYoru>() && !hitActors.Contains(hitResult.GetActor()))
			{
				hitActors.Add(hitResult.GetActor());
				Cast<AYoru>(hitResult.GetActor())->ReceiveDamage(resultDamage, this, hitResult, false);
			}
		}

	}
}

void AEnemyBoss::SetVisible(bool isVisible)
{
	GetMesh()->SetVisibility(isVisible);
	weapon->SetVisibility(isVisible);
}

void AEnemyBoss::StartCounter()
{
	isCounter = true;
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
	FVector DirectionArray[5]{
		GetActorForwardVector(), GetActorRightVector(),
		GetActorForwardVector() * -1, GetActorRightVector() * -1
	};

	int32 RandIndex = FMath::RandHelper(5);
	float DelayTime{ 2.0f };

	if (RandIndex >= 5 || RandIndex < 0)
	{
		RandIndex = 4;
	}

	if (RandIndex == 1 && FVector::Distance(GetActorLocation(), Player->GetActorLocation()) <= 300.0f)
	{
		RandIndex++;
	}

	if (RandIndex == 4)
	{
		DelayTime = 0.5f;
	}

	GetCharacterMovement()->MaxWalkSpeed = RandIndex ? 200.0f : 100.0f;

	if (RandIndex >= 0 && RandIndex < 5)
	{
		BossAIController->MoveToLocation(GetActorLocation() + DirectionArray[RandIndex] * 300.0f);
	}

	FTimerHandle randomMoveTimer{};
	GetWorld()->GetTimerManager().SetTimer(randomMoveTimer, [this]()
		{
			StopRandomMove();
		}, 0.01f, false, DelayTime);
}

bool AEnemyBoss::AttackByAI()
{
	ChangeLockonPlayer(false);
	Attack();

	return false;
}

void AEnemyBoss::StopRandomMove()
{
	OnRandomMoveFinished.ExecuteIfBound();

	GetCharacterMovement()->MaxWalkSpeed = 400.0f;
}