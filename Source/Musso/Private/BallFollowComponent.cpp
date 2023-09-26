// Fill out your copyright notice in the Description page of Project Settings.


#include "BallFollowComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Enemy.h"
#include "BallFollow.h"

// Sets default values for this component's properties
UBallFollowComponent::UBallFollowComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBallFollowComponent::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle MyTimerHandle;

	// Start a timer
	GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &UBallFollowComponent::StartSpawningBalls, 1.0f, false);
	
}


// Called every frame
void UBallFollowComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UBallFollowComponent::StartSpawningBalls()
{
	FTimerHandle MyTimerHandle;
	
	// Start a timer
	GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &UBallFollowComponent::SpawnBall, 4.0f, true);

}

void UBallFollowComponent::SpawnBall()
{
	UE_LOG(LogTemp, Error, TEXT("spawn a ball"));
	AActor* owner = GetOwner();
	if (owner)
	{
		UE_LOG(LogTemp, Error, TEXT("spawn a ball"));
		FVector ownerLocation = owner->GetActorLocation();
		// Créez une nouvelle instance de votre classe de balle
		ABallFollow* NewBall = GetWorld()->SpawnActor<ABallFollow>(projectileBPClass, ownerLocation, FRotator::ZeroRotator);
		closestEnemyUpdate();
		NewBall->setEnemmyToFollow(closestEnemy);

	}

}

void UBallFollowComponent::closestEnemyUpdate()
{
	closestEnemy = nullptr;
	float ClosestDistance = MAX_FLT;

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemy::StaticClass(), FoundActors);

	for (AActor* Enemy : FoundActors)
	{
		if (Enemy)
		{
			FVector EnemyLocation = Enemy->GetActorLocation();
			FVector PlayerLocation = GetOwner()->GetActorLocation();

			float DistanceToEnemy = FVector::Distance(PlayerLocation, EnemyLocation);

			if (DistanceToEnemy < ClosestDistance)
			{
				ClosestDistance = DistanceToEnemy;
				closestEnemy = Cast<AEnemy>(Enemy);
			}
		}
	}
}