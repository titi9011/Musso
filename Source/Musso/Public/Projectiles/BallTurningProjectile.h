// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BallTurningProjectile.generated.h"

UCLASS()
class MUSSO_API ABallTurningProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABallTurningProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<class AExplosion> explosionBPClass;


private:
	void giveDamage();

	void explosion();

	class AMainCharacter* mainCharacter;

	double counter = 0;

	float r = 700.f;

	void setDamage();

	float damage;

};
