#include "IdleState.h"
#include "walkingState.h"
#include "MenuState.h"
#include "MainCharacter.h"

IdleState::IdleState()
{
}

IdleState::~IdleState()
{

}


void IdleState::idle()
{
    UE_LOG(LogTemp, Display, TEXT("Idle State activated"));

    this->MainCharacter->CharacterStruct.state = states::idle;


    if (this->MainCharacter->CharacterStruct.bIsMoving)
    {
        this->MainCharacter->setMainCharacterState(new WalkingState);
    }

    if (this->MainCharacter->CharacterStruct.coins >= this->MainCharacter->CharacterStruct.nbCoinUpgrade)
    {
        this->MainCharacter->setMainCharacterState(new MenuState);
    }
}

void IdleState::walking()
{
}


void IdleState::dead()
{
}


void IdleState::menu()
{

}