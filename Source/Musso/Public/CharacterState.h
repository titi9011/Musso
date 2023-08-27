// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

/**
 * 
 */
class MUSSO_API CharacterState
{
public:
	CharacterState();
	~CharacterState();

protected:
	APawn *Character;

public:

	void setCharacter(APawn *_Character)
	{
		this->Character = _Character;
	}
	
	virtual void idle() = 0;
	virtual void walking() = 0;
	virtual void attacking() = 0;
	virtual void dead() = 0;
};
