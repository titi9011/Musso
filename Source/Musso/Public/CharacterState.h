#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

class AMainCharacter;

class MUSSO_API UCharacterState
{
public:
	UCharacterState();

protected:
	APawn *MainCharacter;

public:

	void setCharacter(APawn *_MainCharacter);

	virtual void idle() = 0;
	virtual void walking() = 0;
	virtual void attacking() = 0;
	virtual void dead() = 0;
};




