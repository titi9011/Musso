// Fill out your copyright notice in the Description page of Project Settings.

#include "MainCharacter.h"
#include "IdleState.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	setMainCharacterState(new IdleState);

}

AMainCharacter::~AMainCharacter()
{
	delete MainCharacterState;

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	runStates();

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void AMainCharacter::setMainCharacterState(UCharacterState *_MainCharacterState)
{
	if (this->MainCharacterState != nullptr)
	{
		delete this->MainCharacterState;
	}
	this->MainCharacterState = _MainCharacterState;
	this->MainCharacterState->setCharacter(this);
}


void AMainCharacter::runStates()
{
	MainCharacterState->idle();
	MainCharacterState->walking();
	MainCharacterState->attacking();
	MainCharacterState->dead();

}