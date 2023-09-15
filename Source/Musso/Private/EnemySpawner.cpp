// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"
#include "Enemy.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle MyTimerHandle;

	// Start a timer
	GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &AEnemySpawner::spawnEnemy, 1.0f, true);
	
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	

}

void AEnemySpawner::spawnEnemy()
{
    float positionX = FMath::FRandRange(bottomLeft.X, topRight.X);
    float positionY = FMath::FRandRange(bottomLeft.Y, topRight.Y);

    FVector position = FVector(positionX, positionY, topRight.Z);

    auto NewBall = GetWorld()->SpawnActor<AEnemy>(enemyBPClass, position, FRotator::ZeroRotator);
}
