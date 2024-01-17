
#include "Enemy.h"
#include "Coin.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "TimerManager.h"

AEnemy::AEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	MainCharacter = Cast<AMainCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	move();

}

void AEnemy::move()
{
	FVector direction = MainCharacter->GetActorLocation() - GetActorLocation();
	
	if (direction.Size() > 200.f)
	{

		direction.Normalize();

		FVector NewLocation = GetActorLocation() + direction*enemyStruct.speed*UGameplayStatics::GetWorldDeltaSeconds(this);

		SetActorLocation(NewLocation);

		SetActorRotation(direction.ToOrientationRotator());

	}
}

void AEnemy::GetDamage(float damage)
{
	if (enemyStruct.health - damage <= 0)
	{
		spawnCoin();
		Destroy();
	}
	else
	{
		enemyStruct.health -= damage;
		materialFlash();

	}
}

void AEnemy::materialFlash()
{
	UStaticMeshComponent* MyMeshComponent = FindComponentByClass<UStaticMeshComponent>();
	if (MyMeshComponent)
	{
		if (flashMaterial)
		{
			MyMeshComponent->SetMaterial(0, flashMaterial);
			
			FTimerHandle MyTimerHandle;

			// Start a timer
			GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &AEnemy::materialBase, 0.1f, false);

		}
	}
}

void AEnemy::materialBase()
{
	UStaticMeshComponent* MyMeshComponent = FindComponentByClass<UStaticMeshComponent>();
	if (MyMeshComponent)
	{
		if (baseMaterial)
		{
			MyMeshComponent->SetMaterial(0, baseMaterial);
		}
	}
}


void AEnemy::spawnCoin()
{
	if (coinBPClass)
	{
		auto newCoin = GetWorld()->SpawnActor<ACoin>(coinBPClass, GetActorLocation(), FRotator::ZeroRotator);
	}
}



float AEnemy::getSpeed()
{
	FVector actualVelocity = GetActorLocation() - lastLocation;
	lastLocation = GetActorLocation();
	return actualVelocity.Size();
}