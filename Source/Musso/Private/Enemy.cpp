// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Kismet/GameplayStatics.h"

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
	move(DeltaTime);

}

void AEnemy::move(float DeltaTime)
{
	FVector direction = MainCharacter->GetActorLocation() - GetActorLocation();
	
	if (direction.Size() > 200.f)
	{

	direction.Normalize();
	AddActorLocalOffset(direction*EnemyStruct.speed*UGameplayStatics::GetWorldDeltaSeconds(this), true);

	}
}

