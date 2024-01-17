#include "States\CharacterState.h"


UCharacterState::UCharacterState()
{
}


void UCharacterState::setCharacter(AMainCharacter *_MainCharacter)
{
	this->MainCharacter = _MainCharacter;
}