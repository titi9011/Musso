// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MainCharacter.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BallProjectile.generated.h"

UCLASS()
class MUSSO_API ABallProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABallProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void giveDamage();

	void explosion();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AExplosion> explosionBPClass;

	UPROPERTY(EditDefaultsOnly)
	class AMainCharacter* mainCharacter;

	FVector ballDirection;

	void setBallDirection();
};
