#pragma once

#include "CoreMinimal.h"
#include "CharacterStruct.generated.h"

enum states
{
	idle,
	walking,
	dead
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
	int state = states::idle;

};

USTRUCT(BlueprintType)
struct FEnemyStruct
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float health = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float speed = 1000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float attackDamage = 0.1f;


};




