#pragma once

#include "CharacterState.h"
#include "Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "CharacterStruct.h"
#include "BallComponent.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

UCLASS()
class MUSSO_API AMainCharacter : public ACharacter
{
    GENERATED_BODY()

	/** MappingContext */
    UPROPERTY(EditAnywhere, Category="Input")
    class UInputMappingContext* DefaultMappingContext;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

public:
    // Sets default values for this pawn's properties
    AMainCharacter();

    ~AMainCharacter();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

    UCharacterState *MainCharacterState;

    void MoveAndRotation(const FInputActionValue& Value);

public:

    FCharacterStruct CharacterStruct;

    UFUNCTION(BlueprintCallable)
    int getState();

	virtual void setMainCharacterState(UCharacterState *_MainCharacterState);

	void runStates();

    void GetDamage();

    void getCoin();

    UPROPERTY(EditDefaultsOnly)
	class UMaterialInterface* flashMaterial;

	UPROPERTY(EditDefaultsOnly)
	class UMaterialInterface* baseMaterial;

private:

	void materialFlash();

	void materialBase();

    void updateBIsMoving();

    FVector lastPosition;

};