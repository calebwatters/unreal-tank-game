// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {
    Super::BeginPlay();

    auto ControlledTank = GetControlledTank();
    if(!ControlledTank) {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing tank"));
    } else
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController  possesing %s"), *(ControlledTank->GetName()));
    }
    
    UE_LOG(LogTemp, Warning, TEXT("Tank controller begin play"));


}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    //AimTowardsCrosshair();

}



ATank* ATankPlayerController::GetControlledTank() const {
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardCrosshair() {
    // Start the tank moving the barrel so the shot would hit where the crosshair intersects the world
    if (!GetControlledTank()) {return;}

    FVector HitLocation;
    if (GetSightRayHitLocation(HitLocation)) {
        UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"),*HitLocation.ToString());


        //Tell controlled tank to aim at point
    }



}

//Get world location if linetrace through crosshair. If it hits the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const {
    HitLocation = FVector(1.0);
    return false;
}