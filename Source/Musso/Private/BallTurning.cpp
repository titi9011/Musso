// Fill out your copyright notice in the Description page of Project Settings.


#include "BallTurning.h"

// Sets default values for this component's properties
UBallTurning::UBallTurning()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBallTurning::BeginPlay()
{
	Super::BeginPlay();


	AActor* owner = GetOwner();
	if (owner)
	{
		FVector ownerLocation = owner->GetActorLocation();
		// Créez une nouvelle instance de votre classe de balle
		auto NewBall = GetWorld()->SpawnActor<ABallTurningProjectile>(BallTurningBPClass, ownerLocation, FRotator::ZeroRotator);
	}

}


// Called every frame
void UBallTurning::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

