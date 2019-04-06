// Copyright Magic Inc., Yernar Aldabergenov© 2019.


#include "TankNavMovementComponent.h"
#include "TankTrackStaticMeshComponent.h"

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

void UTankNavMovementComponent::SetTracks(UTankTrackStaticMeshComponent* LTrack, UTankTrackStaticMeshComponent* RTrack)
{
	this->LTrack = LTrack;
	this->RTrack = RTrack;
}

