// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin.h"
#include "MainCharacter.h"

// Sets default values
ACoin::ACoin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACoin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorWorldRotation(FRotator(0.f, 1.f, 0.f)*100.f*DeltaTime);
	collect();
}

void ACoin::collect()
{
	FVector startLocation = GetActorLocation();

	FVector endLocation = startLocation + FVector(10.0f, 0.0f, 0.0f);

	TArray<FHitResult> hitResults;
	bool bHit = GetWorld()->SweepMultiByChannel(hitResults, startLocation, endLocation, FQuat::Identity, ECC_WorldStatic, FCollisionShape::MakeSphere(100.f));

	if (bHit)
	{
		for (FHitResult hitResult: hitResults)
		{
			AActor* onHitActor = hitResult.GetActor();
			if (onHitActor && onHitActor->ActorHasTag("mainCharacter")) //&& hitResult.GetActor()->ActorHasTag("enemy")
			{
				UE_LOG(LogTemp, Error, TEXT("MainCharacter touch coin!!!"));
				auto mainCharacter = Cast<AMainCharacter>(onHitActor);
				mainCharacter->getCoin();
				Destroy();
			}

		}
	}
}