// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BallFollow.generated.h"

UCLASS()
class MUSSO_API ABallFollow : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABallFollow();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	class AEnemy* enemyToFollow;

	void setEnemmyToFollow(AEnemy* enemyActor);

private:
	
	class AMainCharacter* mainCharacter;

	FVector startPosition;

	FVector direction;

	void updateDirection();

	void giveDamage();


};
