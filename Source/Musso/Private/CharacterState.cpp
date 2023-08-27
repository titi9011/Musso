
#include "CharacterState.h"


// Sets default values
UCharacterState::UCharacterState()
{
}

void UCharacterState::setCharacter(APawn *_MainCharacter)
{
	this->MainCharacter = _MainCharacter;
}