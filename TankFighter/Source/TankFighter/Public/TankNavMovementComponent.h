// Copyright Magic Inc., Yernar Aldabergenov© 2019.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankNavMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class TANKFIGHTER_API UTankNavMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void IntendMoveForward(float Throw);
	
};
