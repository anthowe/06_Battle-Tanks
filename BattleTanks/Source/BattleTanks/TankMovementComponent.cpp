// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "Public/Math/Vector.h"
#include "TankTrack.h"


void UTankMovementComponent::Initialize(UTankTrack *LeftTrackToSet, UTankTrack *RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;

}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankFoward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	
	auto ForwardThrow = FVector::DotProduct(TankFoward, AIForwardIntention);
	IntendMoveForward(ForwardThrow);
	
	auto RightThrow = FVector::CrossProduct(TankFoward, AIForwardIntention).Z;
	IntendTurnRight(RightThrow);

}
void UTankMovementComponent::IntendMoveForward(float Throw)
{

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}


