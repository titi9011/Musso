// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "Golem.generated.h"

/**
 * 
 */
UCLASS()
class MUSSO_API AGolem : public AEnemy
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void move() override;

	void setMainCharacter();

	UFUNCTION(BlueprintCallable)
	float getDistanceToMainCharacter();

private:
	FVector directionNotNormalized = FVector(0.f, 0.f, 0.f);
};