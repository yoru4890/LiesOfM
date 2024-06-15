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

AEnemyBoss::AEnemyBoss()
{
	weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("weaponMesh"));

	redAttackBody = CreateDefaultSubobject<UNiagaraComponent>(TEXT("redAttackBody"));
	redAttackBody->SetupAttachment(GetMesh());
	redAttackWeapon = CreateDefaultSubobject<UNiagaraComponent>(TEXT("redAttackWeapon"));
	redAttackWeapon->SetupAttachment(weapon);

	widgetComp = CreateDefaultSubobject<UBossWidget>(TEXT("widgetComp"));

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
}

void AEnemyBoss::BeginPlay()
{
	Super::BeginPlay();

	maxGroggy = 250.0f;
	currentHealth = maxHealth;
	BossAIController = Cast<AEnemyBossAIController>(GetController());

	Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	bloodFX = LoadObject<UNiagaraSystem>(nullptr, TEXT("/Script/Niagara.NiagaraSystem'/Game/AAA/Effect/Niagara/NS_Blood.NS_Blood'"));
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

	auto temp = FVector::Distance(GetActorLocation(), Player->GetActorLocation());
	UE_LOG(LogTemp, Warning, TEXT("%f"), temp);
}

void AEnemyBoss::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AEnemyBoss::ReceiveDamage(float damageAmount, AActor* attackingActor, const FHitResult& hitResult)
{
	if (!isHittable) return;

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
	
	if (isRedAttack)
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

	currentEnemyState = EEnemyState::Groggy;
	HiddenRedAttack();
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
	if (!(GetMesh()->GetAnimInstance()->IsAnyMontagePlaying()))
	{
		GetMesh()->GetAnimInstance()->Montage_Play(changePhaseMontage);
	}
}

void AEnemyBoss::Attack()
{
	JumpAttack();
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

void AEnemyBoss::meleeAttack1()
{
	if (!(GetMesh()->GetAnimInstance()->IsAnyMontagePlaying()))
	{
		GetMesh()->GetAnimInstance()->Montage_Play(meleeAttack1Montage);
	}
}

void AEnemyBoss::meleeAttack2()
{
	if (!(GetMesh()->GetAnimInstance()->IsAnyMontagePlaying()))
	{
		GetMesh()->GetAnimInstance()->Montage_Play(meleeAttack2Montage);
	}
}

void AEnemyBoss::meleeAttack3()
{
	if (!(GetMesh()->GetAnimInstance()->IsAnyMontagePlaying()))
	{
		GetMesh()->GetAnimInstance()->Montage_Play(meleeAttack3Montage);
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
	float radius{80.0f};
	
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
				Cast<AYoru>(hitResult.GetActor())->ReceiveDamage(resultDamage, this, hitResult);
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
	isRedAttack = true;
	redAttackBody->SetVisibility(true);
	redAttackWeapon->SetVisibility(true);
	ChangeLockonPlayer(true);
	turnSpeed = redAttackTurnSpeed;
}

void AEnemyBoss::HiddenRedAttack()
{
	isRedAttack = false;
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

	BossAIController->MoveToLocation(GetActorLocation() + DirectionArray[RandIndex] * 300.0f);

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
}
