// Fill out your copyright notice in the Description page of Project Settings.

#include "MainCharacter.h"
#include "IdleState.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerController.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"



// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	setMainCharacterState(new IdleState);

	CharacterStruct.speed = 1100.f;

}

AMainCharacter::~AMainCharacter()
{
	delete MainCharacterState;

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (Controller != nullptr)
	{
		if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
			{
				Subsystem->AddMappingContext(DefaultMappingContext, 0);
			}
		}
	}
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
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (EnhancedInputComponent)
	{
		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMainCharacter::Move);
	}
}


void AMainCharacter::Move(const FInputActionValue& Value)
{

	FVector2D MovementVector = Value.Get<FVector2D>();


	if (Controller != nullptr)
	{
		// add movement

		FVector direction = FVector(MovementVector.X,MovementVector.Y,0);
		direction.Normalize();

		AddActorLocalOffset(direction*CharacterStruct.speed*UGameplayStatics::GetWorldDeltaSeconds(this), true);
	}

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

void AMainCharacter::GetDamage()
{
	if (CharacterStruct.health - 0.1f <= 0)
	{
		UE_LOG(LogTemp, Error, TEXT("Dead!!!"));
		//Destroy();
	}
	else
	{
		CharacterStruct.health -= 0.1f;
		UE_LOG(LogTemp, Error, TEXT("Damage!!!"));
	}

}