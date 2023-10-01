// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Enemy.h"
#include "BallFollowComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MUSSO_API UBallFollowComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBallFollowComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite)
	UClass* projectileBPClass;

private:

	FVector direction = FVector(1.f, 0.f, 0.f);

	float speed = 3000.f;

	void StartSpawningBalls();

	void SpawnBall();

	void closestEnemyUpdate();

	AEnemy* closestEnemy;

	void setCastSpeed();

	float castSpeed;

};
