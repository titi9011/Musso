// Fill out your copyright notice in the Description page of Project Settings.


#include "IdleState.h"

IdleState::IdleState()
{
}

IdleState::~IdleState()
{

}


void IdleState::idle()
{
    UE_LOG(LogTemp, Display, TEXT("Idle State activated"));
}

void IdleState::walking()
{
    
}

void IdleState::attacking()
{
    
}

void IdleState::dead()
{
    
}