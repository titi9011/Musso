// Fill out your copyright notice in the Description page of Project Settings.


#include "Components\BallComponent.h"
#include "TimerManager.h"
#include "Projectiles\BallProjectile.h"


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

	StartSpawningBalls();

	
}


// Called every frame
void UBallComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UBallComponent::StartSpawningBalls()
{
	FTimerHandle MyTimerHandle;

	// Start a timer
	GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &UBallComponent::SpawnBall, getCastSpeed(), true);


}

void UBallComponent::SpawnBall()
{
	AActor* owner = GetOwner();
	if (owner)
	{
		FVector ownerLocation = owner->GetActorLocation();
		// Créez une nouvelle instance de votre classe de balle
			auto NewBall = GetWorld()->SpawnActor<AActor>(projectileBPClass, ownerLocation, FRotator::ZeroRotator);
	}
}


float UBallComponent::getCastSpeed()
{

    AMainCharacter* mainCharacter = Cast<AMainCharacter>(GetOwner());

	if (mainCharacter)
	{
		return mainCharacter->CharacterStruct.ballFollowingStruct.castSpeed;
	}
	else
	{
		return 1.0f;
	}

}