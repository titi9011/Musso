// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectiles\BallTurningProjectile.h"
#include <cmath>
#include "MainCharacter.h"
#include "Enemy.h"

// Sets default values
ABallTurningProjectile::ABallTurningProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABallTurningProjectile::BeginPlay()
{
	Super::BeginPlay();

	setDamage();

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);

    if (PlayerController)
    {
        mainCharacter = Cast<AMainCharacter>(PlayerController->GetPawn());
    }
	
}

// Called every frame
void ABallTurningProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	giveDamage();
	counter++;

	float angle = 0.05f*counter;

	FVector around = FVector(r*std::cos(angle), r*std::sin(angle), 0.f);

	if (mainCharacter)
	{
		SetActorLocation(mainCharacter->GetActorLocation() + around);
	}
}

void ABallTurningProjectile::giveDamage()
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
				//explosion();
			}

		}
	}
}

void ABallTurningProjectile::setDamage()
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);

    if (PlayerController)
    {
        mainCharacter = Cast<AMainCharacter>(PlayerController->GetPawn());
    }
	damage = mainCharacter->CharacterStruct.ballTurningStruct.attackDamage;
}


// void ABallTurningProjectile::explosion()
// {

// 	auto NewExplosion = GetWorld()->SpawnActor<AExplosion>(explosionBPClass, GetActorLocation(), FRotator::ZeroRotator);

// }
