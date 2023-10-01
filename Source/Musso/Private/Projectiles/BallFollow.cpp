// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectiles\BallFollow.h"
#include "MainCharacter.h"
#include "Enemy.h"

// Sets default values
ABallFollow::ABallFollow()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABallFollow::BeginPlay()
{
	Super::BeginPlay();

	setDamage();

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);

    if (PlayerController)
    {
        mainCharacter = Cast<AMainCharacter>(PlayerController->GetPawn());
		startPosition = mainCharacter->GetActorLocation();
    }
	
}

// Called every frame
void ABallFollow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	updateDirection();

	AddActorLocalOffset(direction*2000.f*DeltaTime, false);
	giveDamage();


}

void ABallFollow::updateDirection()
{
	if (enemyToFollow)
	{
		direction = enemyToFollow->GetActorLocation() - GetActorLocation();
		direction.Normalize();
	}
}



void ABallFollow::giveDamage()
{
	
	FVector startLocation = GetActorLocation();

	FVector endLocation = startLocation + FVector(10.0f, 0.0f, 0.0f);

	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);
	CollisionParams.bTraceComplex = true;

	TArray<FHitResult> hitResults;
	bool bHit = GetWorld()->SweepMultiByChannel(hitResults, startLocation, endLocation, FQuat::Identity, ECC_WorldStatic, FCollisionShape::MakeSphere(100.0f), CollisionParams);

	if (bHit)
	{
		for (FHitResult hitResult: hitResults)
		{
			AActor* onHitActor = hitResult.GetActor();
			if (onHitActor && onHitActor->ActorHasTag("enemy"))
			{
				auto onHitEnemy = Cast<AEnemy>(onHitActor);
				onHitEnemy->GetDamage(damage);
				Destroy();
			}
			else if (onHitActor && onHitActor->ActorHasTag("wall"))
			{
				Destroy();
			}

		}
	}
}


void ABallFollow::setEnemmyToFollow(AEnemy* enemyActor)
{
	enemyToFollow = enemyActor;
}

void ABallFollow::setDamage()
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);

    if (PlayerController)
    {
        mainCharacter = Cast<AMainCharacter>(PlayerController->GetPawn());
    }
	damage = mainCharacter->CharacterStruct.ballFollowingStruct.attackDamage;
}
