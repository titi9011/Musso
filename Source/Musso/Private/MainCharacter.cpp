// Fill out your copyright notice in the Description page of Project Settings.

#include "MainCharacter.h"
#include "States\IdleState.h"
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

	CharacterStruct.speed = 2000.f;

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

	lastPosition = GetActorLocation();
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	collectCoins();
	updateBIsMoving();
	runStates();

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (EnhancedInputComponent)
	{
		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMainCharacter::MoveAndRotation);
	}
}


void AMainCharacter::MoveAndRotation(const FInputActionValue& Value)
{

	FVector2D MovementVector = Value.Get<FVector2D>();


	if (Controller != nullptr)
	{
		// add movement
		CharacterStruct.direction = FVector(MovementVector.X,MovementVector.Y,0);
		CharacterStruct.direction.Normalize();

		FRotator newRotation = CharacterStruct.direction.Rotation() + FRotator(0.f, -90.f, 0.f);

		FVector newLocation = GetActorLocation() + CharacterStruct.direction*CharacterStruct.speed*UGameplayStatics::GetWorldDeltaSeconds(this);

		SetActorLocationAndRotation(newLocation, newRotation, true);

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
	MainCharacterState->dead();
	MainCharacterState->menu();

}

void AMainCharacter::GetDamage()
{
	if (CharacterStruct.health - 0.1f <= 0)
	{
		UE_LOG(LogTemp, Error, TEXT("Dead!!!"));
		materialFlash();
		//Destroy();
	}
	else
	{
		CharacterStruct.health -= 0.1f;
		materialFlash();
	}

}


void AMainCharacter::materialFlash()
{
	USkeletalMeshComponent* MyMeshComponent = GetMesh();
	if (MyMeshComponent)
	{
		if (flashMaterial)
		{
			MyMeshComponent->SetMaterial(0, flashMaterial);
			
			FTimerHandle MyTimerHandle;

			// Start a timer
			GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &AMainCharacter::materialBase, 0.1f, false);

		}
	}
}

void AMainCharacter::materialBase()
{
	USkeletalMeshComponent* MyMeshComponent = GetMesh();
	if (MyMeshComponent)
	{
		if (baseMaterial)
		{
			MyMeshComponent->SetMaterial(0, baseMaterial);

			UE_LOG(LogTemp, Error, TEXT("flash"));
		}
	}
}

void AMainCharacter::updateBIsMoving()
{
	if (lastPosition == GetActorLocation())
	{
		CharacterStruct.bIsMoving = false;
	}
	else
	{
		CharacterStruct.bIsMoving = true;
	}

	lastPosition = GetActorLocation();
}

int AMainCharacter::getState()
{
	return CharacterStruct.state;
}

float AMainCharacter::getCoinProgression()
{
	return CharacterStruct.coins/ (float) CharacterStruct.nbCoinUpgrade;
}

void AMainCharacter::setCoinsToZero()
{
	CharacterStruct.coins = 0;
}

void AMainCharacter::setIdleState()
{
	CharacterStruct.state = states::idle;
	setMainCharacterState(new IdleState);
}

void AMainCharacter::collectCoins()
{
	FVector startLocation = GetActorLocation();

	FVector endLocation = startLocation + FVector(10.0f, 0.0f, 0.0f);

	TArray<FHitResult> hitResults;
	bool bHit = GetWorld()->SweepMultiByChannel(hitResults, startLocation, endLocation, FQuat::Identity, ECC_WorldStatic, FCollisionShape::MakeSphere(100.f));

	if (bHit)
	{
		for (FHitResult hitResult: hitResults)
		{
			AActor* onHitActor = hitResult.GetActor();
			if (onHitActor && onHitActor->ActorHasTag("coin"))
			{
				CharacterStruct.coins += 1;
				onHitActor->Destroy();
			}

		}
	}
}

void AMainCharacter::increaseCastSpeed()
{
	CharacterStruct.ballProjectileStruct.castSpeed = 0.1;
	CharacterStruct.ballTurningStruct.castSpeed = 0.1;
	CharacterStruct.ballFollowingStruct.castSpeed = 0.1;
}