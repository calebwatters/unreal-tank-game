// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay() {
    Super::BeginPlay();

    auto PlayerTank = GetPlayerTank();
    if(!PlayerTank) {
        UE_LOG(LogTemp, Warning, TEXT("AIController cannot find PlayerTank"));
    } else
    {
        UE_LOG(LogTemp, Warning, TEXT("AIController  found player %s"), *(PlayerTank->GetName()));
    }
    
    UE_LOG(LogTemp, Warning, TEXT("Tank controller begin play"));


}

ATank* ATankAIController::GetControlledTank() const {
    return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const{

    auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
    if(!PlayerPawn) {return nullptr;}
    return Cast<ATank>(PlayerPawn);

}