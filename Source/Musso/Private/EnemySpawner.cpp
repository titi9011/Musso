// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"
#include "Enemy.h"
#include "Golem.h"
#include "Bat.h"

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

FVector AEnemySpawner::spawnPosition()
{
	float positionX = FMath::FRandRange(bottomLeft.X, topRight.X);
    float positionY = FMath::FRandRange(bottomLeft.Y, topRight.Y);

    return FVector(positionX, positionY, topRight.Z);
}

void AEnemySpawner::spawnEnemy()
{
	FVector position = spawnPosition();
    auto NewBall = GetWorld()->SpawnActor<AEnemy>(enemyBPClass, position, FRotator::ZeroRotator);
}

void AEnemySpawner::startSpawningEnemy(float occurence)
{
	GetWorld()->GetTimerManager().SetTimer(enemyTimerHandle, this, &AEnemySpawner::spawnEnemy, occurence, true);
}


void AEnemySpawner::restartSpawningEnemy(float occurence)
{
	GetWorld()->GetTimerManager().ClearTimer(enemyTimerHandle);
	GetWorld()->GetTimerManager().SetTimer(enemyTimerHandle, this, &AEnemySpawner::spawnEnemy, occurence, true);
}


void AEnemySpawner::spawnGolem()
{
	FVector position = spawnPosition();
	auto NewBall = GetWorld()->SpawnActor<AGolem>(golemBPClass, position, FRotator::ZeroRotator);
}

void AEnemySpawner::startSpawningGolem(float occurence)
{
	GetWorld()->GetTimerManager().SetTimer(golemTimerHandle, this, &AEnemySpawner::spawnGolem, occurence, true);
}

void AEnemySpawner::restartSpawningGolem(float occurence)
{
	GetWorld()->GetTimerManager().ClearTimer(golemTimerHandle);
	GetWorld()->GetTimerManager().SetTimer(golemTimerHandle, this, &AEnemySpawner::spawnGolem, occurence, true);
}


void AEnemySpawner::spawnBat()
{
	FVector position = spawnPosition();
	auto NewBall = GetWorld()->SpawnActor<ABat>(batBPClass, position, FRotator::ZeroRotator);
}

void AEnemySpawner::startSpawningBat(float occurence)
{
	GetWorld()->GetTimerManager().SetTimer(batTimerHandle, this, &AEnemySpawner::spawnBat, occurence, true);
}

void AEnemySpawner::restartSpawningBat(float occurence)
{
	GetWorld()->GetTimerManager().ClearTimer(batTimerHandle);
	GetWorld()->GetTimerManager().SetTimer(batTimerHandle, this, &AEnemySpawner::spawnBat, occurence, true);
}


void AEnemySpawner::startLevel1()
{
	startSpawningEnemy(3.f);
	
	UE_LOG(LogTemp, Error, TEXT("Level 1"));
}

void AEnemySpawner::startLevel2()
{
	restartSpawningEnemy(3.f);
	startSpawningGolem(6.f);
}

void AEnemySpawner::startLevel3()
{

	restartSpawningEnemy(3.f);
	startSpawningGolem(6.f);
	restartSpawningBat(3.f);
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