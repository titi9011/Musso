#pragma once

#include "CoreMinimal.h"
#include "CharacterStruct.generated.h"

enum CharacterStates
{
	idle,
	walking,
	attacking,
	dead
};


USTRUCT(BlueprintType)
struct FCharacterStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float health = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float speed = 1000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float attackDamage = 0.1f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int coins = 0;
	
	bool isIdle = true;
	bool isWalking = false;
	bool isAttacking = false;
	bool isDead = false;
};



