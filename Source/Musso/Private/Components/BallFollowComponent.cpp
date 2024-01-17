// Fill out your copyright notice in the Description page of Project Settings.


#include "Components\BallFollowComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Enemy.h"
#include "Projectiles\BallFollow.h"

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

	setCastSpeed();

	FTimerHandle MyTimerHandle;

	// Start a timer
	GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &UBallFollowComponent::StartSpawningBalls, 1.0f, false);
	
}


// Called every frame
void UBallFollowComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UBallFollowComponent::StartSpawningBalls()
{
	FTimerHandle MyTimerHandle;
	
	// Start a timer
	GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &UBallFollowComponent::SpawnBall, castSpeed, true);

}

void UBallFollowComponent::SpawnBall()
{
	AActor* owner = GetOwner();
	if (owner)
	{
		FVector ownerLocation = owner->GetActorLocation();
		closestEnemyUpdate();
		if (closestEnemy)
		{
			ABallFollow* NewBall = GetWorld()->SpawnActor<ABallFollow>(projectileBPClass, ownerLocation, FRotator::ZeroRotator);
			NewBall->setEnemmyToFollow(closestEnemy);
		}

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


void UBallFollowComponent::setCastSpeed()
{

    AMainCharacter* mainCharacter = Cast<AMainCharacter>(GetOwner());

	castSpeed = mainCharacter->CharacterStruct.ballFollowingStruct.castSpeed;
}