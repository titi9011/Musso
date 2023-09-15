// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class MUSSO_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AEnemy> enemyBPClass;

	void spawnEnemy();

	FVector topRight = FVector(7524.25f, 6091.64f, 270.00f);
	FVector bottomLeft = FVector(-5190.48f, -15485.55f, 270.00f);


};
