#include "Projectiles\Explosion.h"


AExplosion::AExplosion()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AExplosion::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle MyTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &AExplosion::destroy, 2.0f, true);
	
}

void AExplosion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AExplosion::destroy()
{
	Destroy();
	
}