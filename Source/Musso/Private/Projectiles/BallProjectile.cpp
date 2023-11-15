// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectiles\BallProjectile.h"
#include "Enemy.h"
#include "Golem.h"
#include "Bat.h"
#include "Projectiles\Explosion.h"

// Sets default values
ABallProjectile::ABallProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABallProjectile::BeginPlay()
{
	Super::BeginPlay();

	setDamage();

	setBallDirection();

}

// Called every frame
void ABallProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	giveDamage();

	if (mainCharacter)
	{
		AddActorLocalOffset(ballDirection*3000.f*DeltaTime, true);
	}
}

void ABallProjectile::giveDamage()
{
	
	FVector startLocation = GetActorLocation();

	FVector endLocation = startLocation + FVector(10.0f, 0.0f, 0.0f);

	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);
	CollisionParams.bTraceComplex = true;

	TArray<FHitResult> hitResults;
	bool bHit = GetWorld()->SweepMultiByChannel(hitResults, startLocation, endLocation, FQuat::Identity, ECC_WorldStatic, FCollisionShape::MakeSphere(100.0f), CollisionParams);

	if (bHit)
	{
		for (FHitResult hitResult: hitResults)
		{
			AActor* onHitActor = hitResult.GetActor();
			if (onHitActor && onHitActor->ActorHasTag("enemy"))
			{
				auto onHitEnemy = Cast<AEnemy>(onHitActor);
				onHitEnemy->GetDamage(damage);
				explosion();
				Destroy();
			}
			else if (onHitActor && onHitActor->ActorHasTag("bat"))
			{
				auto onHitEnemy = Cast<ABat>(onHitActor);
				onHitEnemy->GetDamage(damage);
				explosion();
				Destroy();
			}
			else if (onHitActor && onHitActor->ActorHasTag("golem"))
			{
				auto onHitGolem = Cast<AGolem>(onHitActor);
				onHitGolem->GetDamage(damage);
				explosion();
				Destroy();
			}
			else if (onHitActor && onHitActor->ActorHasTag("wall"))
			{
				explosion();
				Destroy();
			}

		}
	}
}


void ABallProjectile::explosion()
{

	auto NewExplosion = GetWorld()->SpawnActor<AExplosion>(explosionBPClass, GetActorLocation(), FRotator::ZeroRotator);

}

void ABallProjectile::setBallDirection()
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);

    if (PlayerController)
    {
        mainCharacter = Cast<AMainCharacter>(PlayerController->GetPawn());

		if (mainCharacter)
		{
			ballDirection = mainCharacter->CharacterStruct.direction;
		}
    }
}


void ABallProjectile::setDamage()
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);

    if (PlayerController)
    {
        mainCharacter = Cast<AMainCharacter>(PlayerController->GetPawn());
    }
	damage = mainCharacter->CharacterStruct.ballProjectileStruct.attackDamage;
}