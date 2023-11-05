// Fill out your copyright notice in the Description page of Project Settings.


#include "Bat.h"
#include "MainCharacter.h"
#include "Coin.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "TimerManager.h"

// Sets default values
ABat::ABat()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABat::BeginPlay()
{
	Super::BeginPlay();

	MainCharacter = Cast<AMainCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	enemyStruct.health = 5.f;
}

// Called every frame
void ABat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABat::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABat::GetDamage(float damage)
{
	if (enemyStruct.health - damage <= 0)
	{
		spawnCoin();
		Destroy();
	}
	else
	{
		enemyStruct.health -= damage;
		materialFlash();
	}
}

void ABat::materialFlash()
{
	UStaticMeshComponent* MyMeshComponent = FindComponentByClass<UStaticMeshComponent>();
	if (MyMeshComponent)
	{
		if (flashMaterial)
		{
			MyMeshComponent->SetMaterial(0, flashMaterial);
			
			FTimerHandle MyTimerHandle;

			// Start a timer
			GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &ABat::materialBase, 0.1f, false);
		}
	}
}

void ABat::materialBase()
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


void ABat::spawnCoin()
{
	if (coinBPClass)
	{
		auto newCoin = GetWorld()->SpawnActor<ACoin>(coinBPClass, GetActorLocation(), FRotator::ZeroRotator);
	}
}

