// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#pragma once

#include "CharacterState.h"
#include "CoreMinimal.h"

/**
 * 
 */
class MUSSO_API MenuState : public UCharacterState
{
public:
	MenuState();
	virtual ~MenuState();

	void idle() override;
	void walking() override;
	void dead() override;
	void menu() override;
};
