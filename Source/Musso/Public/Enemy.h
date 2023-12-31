// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MainCharacter.h"
#include "CharacterStruct.h"
#include "Enemy.generated.h"

UCLASS()
class MUSSO_API AEnemy : public APawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FEnemyStruct enemyStruct;

	void GetDamage(float damage);

	UPROPERTY(EditDefaultsOnly)
	class UMaterialInterface* flashMaterial;

	UPROPERTY(EditDefaultsOnly)
	class UMaterialInterface* baseMaterial;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class ACoin> coinBPClass;

	UFUNCTION(BlueprintCallable)
	float getSpeed();
	

private:
	void move();

	AMainCharacter* MainCharacter;

	void materialFlash();

	void materialBase();

	void spawnCoin();

	FVector lastLocation = FVector(0.f, 0.f, 0.f);


};
