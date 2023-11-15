#pragma once

#include "CoreMinimal.h"
#include "CharacterStruct.generated.h"

enum states
{
	idle,
	walking,
	dead,
	menu
};

USTRUCT(BlueprintType)
struct FAttackStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float attackDamage = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float castSpeed = 1.f;

};


USTRUCT(BlueprintType)
struct FCharacterStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector direction = FVector(0.f, 0.f, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float health = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float speed = 1000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float attackDamage = 0.1f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int coins = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int nbCoinUpgrade = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int state = states::idle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsMoving = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FAttackStruct ballProjectileStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FAttackStruct ballTurningStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FAttackStruct ballFollowingStruct;

};

USTRUCT(BlueprintType)
struct FEnemyStruct
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float health = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float speed = 800.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float attackDamage = 0.1f;

};




