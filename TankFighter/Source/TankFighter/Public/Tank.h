// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimComponent;

UCLASS()
class TANKFIGHTER_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UTankAimComponent* TankAimComponent = nullptr;

public:	
	// Called every frame
	virtual void Tick(float) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent*) override;

	// Player and AI's aimping point
	void AimAt(FVector&);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTankBarrel(UTankBarrelStaticMeshComponent* TankBarrel);
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTankTurret(UTankTurretStaticMeshComponent* TankTurret);
	UFUNCTION(BlueprintCallable)
		void Fire();
	UPROPERTY(EditAnywhere, Category = Firing)
		float ProjectileSpeed = 5000.f; /// Launch speed of a missile. cm -> meter = 500 m/s;
};
