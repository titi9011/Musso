
#include "States\MenuState.h"
#include "States\walkingState.h"
#include "States\IdleState.h"
#include "Blueprint/UserWidget.h"
#include "Engine/World.h"
#include "MainCharacter.h"

MenuState::MenuState()
{
}

MenuState::~MenuState()
{
}

void MenuState::idle()
{
}

void MenuState::walking()
{
}


void MenuState::dead()
{
}

void MenuState::menu()
{
    UE_LOG(LogTemp, Display, TEXT("menu State"));
    
    this->MainCharacter->CharacterStruct.state = states::menu;

}