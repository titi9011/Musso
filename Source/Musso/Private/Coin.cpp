#include "Coin.h"
#include "MainCharacter.h"

ACoin::ACoin()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACoin::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorWorldRotation(FRotator(0.f, 1.f, 0.f)*100.f*DeltaTime);
}
