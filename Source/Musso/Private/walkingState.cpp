// Fill out your copyright notice in the Description page of Project Settings.


#include "walkingState.h"
#include "IdleState.h"
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
}


void WalkingState::dead()
{
}