// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"




void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	//auto AIControlledTank = GetAIControlledTank();
	/*if (!AIControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No AI Controlled Tank found."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller found tank: %s"), *(AIControlledTank->GetName()));
	}*/
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Player one found."));
	}
	else
	{
			
		UE_LOG(LogTemp, Warning, TEXT("AI Controller found tank: %s"), *(PlayerTank->GetName()));
	}
}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast <ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
FVector HitLocation;
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) {return nullptr;}
	return Cast <ATank> (PlayerPawn);
	//GetPlayerTank()-> AimAt(HitLocation);
}