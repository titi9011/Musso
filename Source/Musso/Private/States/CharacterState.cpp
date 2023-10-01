
#include "States\CharacterState.h"


// Sets default values
UCharacterState::UCharacterState()
{
}


void UCharacterState::setCharacter(AMainCharacter *_MainCharacter)
{
	this->MainCharacter = _MainCharacter;
}