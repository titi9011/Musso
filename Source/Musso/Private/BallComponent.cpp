// Fill out your copyright notice in the Description page of Project Settings.


#include "BallComponent.h"
#include "TimerManager.h"

// Sets default values for this component's properties
UBallComponent::UBallComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBallComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBallComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UBallComponent::StartSpawningBalls()
{
	//FTimerHandle MyTimerHandle;
    //GetWorldTimerManager().SetTimer(MyTimerHandle, this, &AMyCharacter::SpawnBall, 1.0f, true, 1.0f);
}

void UBallComponent::SpawnBall()
{
    // Créez une nouvelle instance de votre classe de balle
    //ABall* NewBall = GetWorld()->SpawnActor<ABall>(BallClass, GetActorLocation(), FRotator::ZeroRotator);

    // Configurez d'autres propriétés de la balle si nécessaire
}