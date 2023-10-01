// Fill out your copyright notice in the Description page of Project Settings.


#include "Components\CloseAttack.h"
#include "MainCharacter.h"

// Sets default values for this component's properties
UCloseAttack::UCloseAttack()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCloseAttack::BeginPlay()
{
	Super::BeginPlay();

	startAttacking();
	
}


// Called every frame
void UCloseAttack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UCloseAttack::startAttacking()
{
	FTimerHandle MyTimerHandle;

	// Start a timer
	GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &UCloseAttack::attack, 1.0f, true);
}

void UCloseAttack::attack()
{
	FVector startLocation = GetOwner()->GetActorLocation();

	FVector endLocation = startLocation + FVector(10.0f, 0.0f, 0.0f);

	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(GetOwner());
	CollisionParams.bTraceComplex = true;

	TArray<FHitResult> hitResults;
	bool bHit = GetWorld()->SweepMultiByChannel(hitResults, startLocation, endLocation, FQuat::Identity, ECC_WorldStatic, FCollisionShape::MakeSphere(250.0f), CollisionParams);

	
	if (bHit)
	{
		for (FHitResult hitResult: hitResults)
		{
			AActor* onHitActor = hitResult.GetActor();
			if (onHitActor && onHitActor->ActorHasTag("mainCharacter"))
			{
				auto onHitMainCharacter = Cast<AMainCharacter>(onHitActor);
				onHitMainCharacter->GetDamage();
			}

		}
	}
}
