// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CharacterState.h"
#include "CoreMinimal.h"

/**
 * 
 */
class MUSSO_API IdleState : public UCharacterState
{
public:
	IdleState();
	virtual ~IdleState();

	void idle() override;
	void walking() override;
	void dead() override;
	void menu() override;
};
