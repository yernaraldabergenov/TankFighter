// Copyright Magic Inc., Yernar Aldabergenov© 2019.


#include "TankNavMovementComponent.h"
#include "TankTrackStaticMeshComponent.h"

void UTankNavMovementComponent::SetTracks(UTankTrackStaticMeshComponent* LTrack, UTankTrackStaticMeshComponent* RTrack)
{
	this->LTrack = LTrack;
	this->RTrack = RTrack;
}

void UTankNavMovementComponent::IntendMoveForward(float Throw)
{
	///UE_LOG(LogTemp, Warning, TEXT("Moving with: %f"), Throw)
	if (!(LTrack && RTrack)) return;
	LTrack->SetThrottle(Throw);
	RTrack->SetThrottle(Throw);
}

void UTankNavMovementComponent::IntendTurnRight(float Throw)
{
	///UE_LOG(LogTemp, Warning, TEXT("Moving with: %f"), Throw)
	if (!(LTrack && RTrack)) return;
	LTrack->SetThrottle(Throw);
	RTrack->SetThrottle(-Throw);
}

void UTankNavMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	///UE_LOG(LogTemp, Warning, TEXT("Velocity of %s: %s"), *GetOwner()->GetName(), *MoveVelocity.ToCompactString())
	float ForwardThrow = FVector::DotProduct((GetOwner()->GetActorForwardVector().GetSafeNormal()), (MoveVelocity.GetSafeNormal()));
	float RightThrow = FVector::CrossProduct((GetOwner()->GetActorForwardVector().GetSafeNormal()), (MoveVelocity.GetSafeNormal())).Z;
	IntendMoveForward(ForwardThrow);
	IntendTurnRight(RightThrow);
}



