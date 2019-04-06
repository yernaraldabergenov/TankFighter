// Copyright Magic Inc., Yernar Aldabergenov© 2019.

#include "Tank.h"
#include "TankAimComponent.h"
#include "Projectile.h"
#include "TankBarrelStaticMeshComponent.h"
#include "TankNavMovementComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	/// TankAimComponent = CreateDefaultSubobject<UTankAimComponent>(FName("Aim Components"));
	/// TankMovementComponent = CreateDefaultSubobject<UTankNavMovementComponent>(FName("Movement Components"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
/*void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}*/

void ATank::AimAt(FVector& HitLocation)
{
	/// UE_LOG(LogTemp, Warning, TEXT("TEST ATANK AIMAT"))
	TankAimComponent->AimAt(HitLocation, ProjectileSpeed);
}



void ATank::Fire()
{
	bool bIsReloaded = ((FPlatformTime::Seconds() - LastFireTime) > FireCooldown);
	UTankBarrelStaticMeshComponent *TankBarrel = TankAimComponent->GetTankBarrel();
	if (TankBarrel && bIsReloaded)
	{
		AProjectile *Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileType,
			(TankBarrel->GetSocketLocation(FName("ProjectileSocket"))),
			(TankBarrel->GetSocketRotation(FName("ProjectileSocket"))));
		Projectile->LaunchProjectile(ProjectileSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}