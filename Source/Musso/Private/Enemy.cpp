// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Coin.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	MainCharacter = Cast<AMainCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	move();

}

void AEnemy::move()
{
	FVector direction = MainCharacter->GetActorLocation() - GetActorLocation();
	
	if (direction.Size() > 200.f)
	{

	direction.Normalize();
	AddActorLocalOffset(direction*enemyStruct.speed*UGameplayStatics::GetWorldDeltaSeconds(this), true);

	}
}

void AEnemy::GetDamage()
{
	if (enemyStruct.health - 0.5f <= 0)
	{
		spawnCoin();
		Destroy();
	}
	else
	{
		enemyStruct.health -= 0.5f;
		materialFlash();

	}
}

void AEnemy::materialFlash()
{
	UStaticMeshComponent* MyMeshComponent = FindComponentByClass<UStaticMeshComponent>();
	if (MyMeshComponent)
	{
		if (flashMaterial)
		{
			MyMeshComponent->SetMaterial(0, flashMaterial);
			
			FTimerHandle MyTimerHandle;

			// Start a timer
			GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &AEnemy::materialBase, 0.1f, false);

		}
	}
}

void AEnemy::materialBase()
{
	UStaticMeshComponent* MyMeshComponent = FindComponentByClass<UStaticMeshComponent>();
	if (MyMeshComponent)
	{
		if (baseMaterial)
		{
			MyMeshComponent->SetMaterial(0, baseMaterial);
		}
	}
}


void AEnemy::spawnCoin()
{
	if (coinBPClass)
	{
		auto newCoin = GetWorld()->SpawnActor<ACoin>(coinBPClass, GetActorLocation(), FRotator::ZeroRotator);
	}
}