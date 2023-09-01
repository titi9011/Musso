// Fill out your copyright notice in the Description page of Project Settings.


#include "walkingState.h"


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
}

void WalkingState::attacking()
{
}

void WalkingState::dead()
{
}