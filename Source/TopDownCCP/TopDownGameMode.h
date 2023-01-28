// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TopDownGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNCCP_API ATopDownGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	ATopDownGameMode();

	UPROPERTY(EditAnywhere, Category = "Spawn")
		TSubclassOf<class AFood> FoodBlueprint;

	UPROPERTY(EditAnywhere, Category = "Spawn")
		TSubclassOf<class AEnemy> EnemyBlueprint;

	float SpawnTimer;

	virtual void Tick(float DeltaTime) override;

	FVector GenerateRandomLocation();

	void OnGameOver();
};
