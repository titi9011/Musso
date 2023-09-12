// Fill out your copyright notice in the Description page of Project Settings.


#include "Explosion.h"

// Sets default values
AExplosion::AExplosion()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AExplosion::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle MyTimerHandle;

	GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &AExplosion::destroy, 2.0f, true);
	
}

// Called every frame
void AExplosion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AExplosion::destroy()
{
	Destroy();
	
}