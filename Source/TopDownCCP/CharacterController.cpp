// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterController.h"

// Sets default values
ACharacterController::ACharacterController()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ACharacterController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!CurrentVelocity.IsZero()) 
	{
		FVector NewCharacterPosition = GetActorLocation() + (Speed * CurrentVelocity * DeltaTime);

		SetActorLocation(NewCharacterPosition);
	}
}

// Called to bind functionality to input
void ACharacterController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveHorizontally", this, &ACharacterController::MoveHorizontally);
	PlayerInputComponent->BindAxis("MoveVertically", this, &ACharacterController::MoveVertically);
}

void ACharacterController::MoveHorizontally(float AxisValue)
{
	CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}

void ACharacterController::MoveVertically(float AxisValue)
{
	CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}