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

	virtual void enter() = 0;
	virtual void update() = 0;
	virtual void exit() = 0;

};




