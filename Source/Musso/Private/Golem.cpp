// Fill out your copyright notice in the Description page of Project Settings.


#include "Golem.h"
#include "MainCharacter.h"
#include "Coin.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "TimerManager.h"


// Sets default values
AGolem::AGolem()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGolem::BeginPlay()
{
	Super::BeginPlay();

	MainCharacter = Cast<AMainCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
}

// Called every frame
void AGolem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGolem::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AGolem::GetDamage(float damage)
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

void AGolem::materialFlash()
{
	UStaticMeshComponent* MyMeshComponent = FindComponentByClass<UStaticMeshComponent>();
	if (MyMeshComponent)
	{
		if (flashMaterial)
		{
			MyMeshComponent->SetMaterial(0, flashMaterial);
			
			FTimerHandle MyTimerHandle;

			// Start a timer
			GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &AGolem::materialBase, 0.1f, false);
		}
	}
}

void AGolem::materialBase()
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


void AGolem::spawnCoin()
{
	if (coinBPClass)
	{
		auto newCoin = GetWorld()->SpawnActor<ACoin>(coinBPClass, GetActorLocation(), FRotator::ZeroRotator);
	}
}

