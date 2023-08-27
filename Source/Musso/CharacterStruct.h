#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
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

public:
	FCharacterStruct() = default;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float health = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float speed = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float attackDamage = 0.1;
	
	bool isIdle = true;
	bool isWalking = false;
	bool isAttacking = false;
	bool isDead = false;
};



