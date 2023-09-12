// Fill out your copyright notice in the Description page of Project Settings.


#include "BallProjectile.h"
#include "Enemy.h"

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
	
}

// Called every frame
void ABallProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	giveDamage();
	AddActorLocalOffset(FVector(0.f, 1.f, 0.f)*2000.f*DeltaTime, true);
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

	//DrawDebugSphere(GetWorld(), startLocation, 100.0f, 12, FColor::Red, false, 1.f);

	for (FHitResult hitResult: hitResults)
	{
		AActor* onHitActor = hitResult.GetActor();
		if (onHitActor && onHitActor->ActorHasTag("enemy")) //&& hitResult.GetActor()->ActorHasTag("enemy")
		{
			UE_LOG(LogTemp, Error, TEXT("enemy"));
			auto onHitEnemy = Cast<AEnemy>(onHitActor);
			onHitEnemy->GetDamage();

			Destroy();
		}
	}
}
