// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
class UTankAimingComponent;

/**
*Responsible for helping the player aim.
*/

UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent *AimCompRef);

public:
	

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	
	
	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.3333;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000.0;
	
	bool GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	
	
};
