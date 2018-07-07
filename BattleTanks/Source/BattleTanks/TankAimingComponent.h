// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UENUM ()
enum class EFiringState : uint8 {Locked, Aiming, Reloading};

class UTankBarrel;
class UTankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	void SetBarrelReference(UTankBarrel * BarrelToSet);
	void SetTurretReference(UTankTurret * TurretToSet);
protected:
	// Called when the game starts


public:	
	// Called every frame


	void AimAt(FVector HitLocation, float LaunchSpeed);
	void RotateTo(FVector HitLocation, float LaunchSpeed);
protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Aiming;



private:
	

	UTankBarrel * Barrel = nullptr;
	
	UTankTurret * Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
	
	void RotateTurret(FVector AimDirection);

	
};
