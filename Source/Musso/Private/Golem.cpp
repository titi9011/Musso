// Fill out your copyright notice in the Description page of Project Settings.


#include "Golem.h"
#include "MainCharacter.h"
#include "Coin.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "TimerManager.h"

void AGolem::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle MyTimerHandle;

	// Start a timer
	GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &AGolem::setMainCharacter, 0.01f, false);


}

void AGolem::setMainCharacter()
{
	MainCharacter = Cast<AMainCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
}

void AGolem::Tick(float DeltaTime)
{

	
}

void AGolem::move()
{
	if (MainCharacter)
	{
		FVector direction = MainCharacter->GetActorLocation() - GetActorLocation();

		directionNotNormalized = direction;

		direction.Normalize();
		
		FVector NewLocation = GetActorLocation() + direction*enemyStruct.speed*UGameplayStatics::GetWorldDeltaSeconds(this);

		SetActorLocationAndRotation(NewLocation, direction.ToOrientationRotator(), true);
	}
}

float AGolem::getDistanceToMainCharacter()
{
	float distance = directionNotNormalized.Size();
	UE_LOG(LogTemp, Error, TEXT("%f"), distance);
	return distance;
}