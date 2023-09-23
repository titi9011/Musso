#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

class AMainCharacter;

class MUSSO_API UCharacterState
{
public:
	UCharacterState();
	virtual ~UCharacterState() = default;

protected:
	AMainCharacter *MainCharacter;

public:

	void setCharacter(AMainCharacter *_MainCharacter);

	virtual void idle() = 0;
	virtual void walking() = 0;
	virtual void dead() = 0;
	virtual void menu() = 0;
};




