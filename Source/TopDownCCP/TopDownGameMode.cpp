// Fill out your copyright notice in the Description page of Project Settings.

#include "TopDownGameMode.h"
#include "Food.h"

ATopDownGameMode::ATopDownGameMode() : Super()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATopDownGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SpawnTimer -= DeltaTime;

	if (SpawnTimer < 0.0f)
	{
		float NumberOfSecondsBetweenSpawn = 1.0f;

		SpawnTimer = NumberOfSecondsBetweenSpawn;

		UWorld* world = GetWorld();

		if (world)
		{
			FVector foodLocation = GenerateRandomLocation();

			AFood* food = world->SpawnActor<AFood>(FoodBlueprint, foodLocation, FRotator::ZeroRotator);
		}
	}
}

FVector ATopDownGameMode::GenerateRandomLocation()
{
	FVector location;

	float minimum = 100;
	float maximum = 1000;

	location.X = FMath::RandRange(minimum, maximum);
	location.Y = FMath::RandRange(minimum, maximum);
	location.Z = 0;

	return location;
}