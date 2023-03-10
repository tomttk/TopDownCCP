// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CharacterController.generated.h"

UCLASS()
class TOPDOWNCCP_API ACharacterController : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACharacterController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
		float Speed = 10;

	FVector CurrentVelocity;

	void MoveHorizontally(float AxisValue);
	void MoveVertically(float AxisValue);

	UPROPERTY(EditAnywhere)
		UShapeComponent* CollisionBox;

	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
