
#include "Components\BallComponent.h"
#include "TimerManager.h"
#include "Projectiles\BallProjectile.h"



UBallComponent::UBallComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

UBallComponent::~UBallComponent()
{
	 
}


// Called when the game starts
void UBallComponent::BeginPlay()
{
	Super::BeginPlay();
	StartSpawningBalls();

}


void UBallComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


}


void UBallComponent::StartSpawningBalls()
{
	GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &UBallComponent::SpawnBall, getCastSpeed(), true);

}

void UBallComponent::StopSpawningBalls()
{
	GetWorld()->GetTimerManager().ClearTimer(MyTimerHandle);
}

void UBallComponent::SpawnBall()
{
	AActor* owner = GetOwner();
	if (owner)
	{
		FVector ownerLocation = owner->GetActorLocation();

		auto NewBall = GetWorld()->SpawnActor<AActor>(projectileBPClass, ownerLocation, FRotator::ZeroRotator);
	}
}


float UBallComponent::getCastSpeed()
{

    AMainCharacter* mainCharacter = Cast<AMainCharacter>(GetOwner());

	if (mainCharacter)
	{
		return mainCharacter->CharacterStruct.ballFollowingStruct.castSpeed;
	}
	else
	{
		return 1.0f;
	}

}