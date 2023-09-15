#include "IdleState.h"
#include "walkingState.h"
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
    
    //this->MainCharacter->setMainCharacterState(new WalkingState);
}

void IdleState::walking()
{
    
}


void IdleState::dead()
{
    
}