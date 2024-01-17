// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "walkingState.h"
#include "CharacterState.h"
#include "CoreMinimal.h"

/**
 * 
 */
class MUSSO_API WalkingState : public UCharacterState
{
public:
	WalkingState();
	virtual ~WalkingState();

	void enter() override;
	void update() override;
	void exit() override;
};
