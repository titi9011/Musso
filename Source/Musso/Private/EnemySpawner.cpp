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
	currentLevel = 0;
	nextLevel();
	
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

void AEnemySpawner::startSpawningEnemy(float occurence)
{
	GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &AEnemySpawner::spawnEnemy, occurence, true);

}

void AEnemySpawner::restartSpawningEnemy(float occurence)
{
	GetWorld()->GetTimerManager().ClearTimer(MyTimerHandle);
	GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &AEnemySpawner::spawnEnemy, occurence, true);
}

void AEnemySpawner::startLevel1()
{
	startSpawningEnemy(0.1f);
	UE_LOG(LogTemp, Error, TEXT("Level 1"));

}

void AEnemySpawner::startLevel2()
{
	restartSpawningEnemy(.01f);

}

void AEnemySpawner::startLevel3()
{
	restartSpawningEnemy(0.001f);

}
 

void AEnemySpawner::nextLevel()
{
	currentLevel++;
	switch (currentLevel)
	{
		case 1:
			startLevel1();
			break;
			
		case 2:
			startLevel2();
			break;

		case 3:
			startLevel3();
			break;
		default:
        	break;
	}
}