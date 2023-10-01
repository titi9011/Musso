// Fill out your copyright notice in the Description page of Project Settings.


#include "Components\BallTurning.h"
#include "TimerManager.h"

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

	FTimerHandle MyTimerHandle;

	// Start a timer
	GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &UBallTurning::spawnTurningBall, 1.0f, false);

}


// Called every frame
void UBallTurning::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UBallTurning::spawnTurningBall()
{
	AActor* owner = GetOwner();
	if (owner)
	{
		FVector ownerLocation = owner->GetActorLocation();
		// Créez une nouvelle instance de votre classe de balle

		if (BallTurningBPClass)
		{
			UE_LOG(LogTemp, Error, TEXT("pointeur working!!!!"));
			auto NewBall = GetWorld()->SpawnActor<ABallTurningProjectile>(BallTurningBPClass, ownerLocation, FRotator::ZeroRotator);
		}
	}
}