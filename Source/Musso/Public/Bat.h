// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterStruct.h"
#include "Bat.generated.h"

UCLASS()
class MUSSO_API ABat : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABat();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FEnemyStruct enemyStruct;

	void GetDamage(float damage);

	UPROPERTY(EditDefaultsOnly)
	class UMaterialInterface* flashMaterial;

	UPROPERTY(EditDefaultsOnly)
	class UMaterialInterface* baseMaterial;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class ACoin> coinBPClass;
	
private:

	class AMainCharacter* MainCharacter;

	void materialFlash();

	void materialBase();

	void spawnCoin();

	FVector lastLocation = FVector(0.f, 0.f, 0.f);
};
