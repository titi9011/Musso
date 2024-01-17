

#include "Components\BallTurning.h"
#include "TimerManager.h"

UBallTurning::UBallTurning()
{

	PrimaryComponentTick.bCanEverTick = true;

}


void UBallTurning::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle MyTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &UBallTurning::spawnTurningBall, 1.0f, false);

}


void UBallTurning::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UBallTurning::spawnTurningBall()
{
	AActor* owner = GetOwner();
	if (owner)
	{
		FVector ownerLocation = owner->GetActorLocation();

		if (BallTurningBPClass)
		{
			UE_LOG(LogTemp, Error, TEXT("pointeur working!!!!"));
			auto NewBall = GetWorld()->SpawnActor<ABallTurningProjectile>(BallTurningBPClass, ownerLocation, FRotator::ZeroRotator);
		}
	}
}