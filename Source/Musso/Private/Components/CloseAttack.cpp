#include "Components\CloseAttack.h"
#include "MainCharacter.h"


UCloseAttack::UCloseAttack()
{
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UCloseAttack::BeginPlay()
{
	Super::BeginPlay();

	startAttacking();
	
}


void UCloseAttack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UCloseAttack::startAttacking()
{
	FTimerHandle MyTimerHandle;

	GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &UCloseAttack::attack, 1.0f, true);
}

void UCloseAttack::attack()
{
	FVector startLocation = GetOwner()->GetActorLocation();

	FVector endLocation = startLocation + FVector(10.0f, 0.0f, 0.0f);

	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(GetOwner());
	CollisionParams.bTraceComplex = true;

	TArray<FHitResult> hitResults;
	bool bHit = GetWorld()->SweepMultiByChannel(hitResults, startLocation, endLocation, FQuat::Identity, ECC_WorldStatic, FCollisionShape::MakeSphere(250.0f), CollisionParams);

	
	if (bHit)
	{
		for (FHitResult hitResult: hitResults)
		{
			AActor* onHitActor = hitResult.GetActor();
			if (onHitActor && onHitActor->ActorHasTag("mainCharacter"))
			{
				auto onHitMainCharacter = Cast<AMainCharacter>(onHitActor);
				onHitMainCharacter->GetDamage();
			}

		}
	}
}
