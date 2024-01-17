
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

void MenuState::enter()
{
    this->MainCharacter->CharacterStruct.state = states::menu;
}


void MenuState::update()
{

}


void MenuState::exit()
{

}
