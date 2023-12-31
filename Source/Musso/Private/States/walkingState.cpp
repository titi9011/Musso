// Fill out your copyright notice in the Description page of Project Settings.


#include "States\walkingState.h"
#include "States\IdleState.h"
#include "States\MenuState.h"
#include "MainCharacter.h"

WalkingState::WalkingState()
{
}

WalkingState::~WalkingState()
{
}

void WalkingState::idle()
{
}

void WalkingState::walking()
{
    UE_LOG(LogTemp, Display, TEXT("Walking State activated"));

    this->MainCharacter->CharacterStruct.state = states::walking;


    if (this->MainCharacter->CharacterStruct.bIsMoving == false)
    {
        this->MainCharacter->setMainCharacterState(new IdleState);
    }

    if (this->MainCharacter->CharacterStruct.coins >= this->MainCharacter->CharacterStruct.nbCoinUpgrade)
    {
        this->MainCharacter->setMainCharacterState(new MenuState);
    }
}


void WalkingState::dead()
{
}


void WalkingState::menu()
{
}