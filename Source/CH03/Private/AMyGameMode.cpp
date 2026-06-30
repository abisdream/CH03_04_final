// Fill out your copyright notice in the Description page of Project Settings.


#include "AMyGameMode.h"
#include "APawnTest.h"
#include "TestPlayerController.h"
#include "Coin.h"
#include "HealthPotion.h"
#include "LandMine.h"


AAMyGameMode::AAMyGameMode()
{
    DefaultPawnClass = AAPawnTest::StaticClass();
    PlayerControllerClass = ATestPlayerController::StaticClass();
}

void AAMyGameMode::BeginPlay()
{
    Super::BeginPlay();

    StartWave();
}

void AAMyGameMode::StartWave()
{
    switch (CurrentWave)
    {
    case 1:
        RemainingTime = 15.f;
        break;

    case 2:
        RemainingTime = 10.f;
        break;

    case 3:
        RemainingTime = 5.f;
        break;

    default:
        UE_LOG(LogTemp, Warning, TEXT("Level Clear!"));
        return;
    }

    

    UE_LOG(LogTemp, Warning, TEXT("Wave %d Ω√¿€!"), CurrentWave);

    SpawnWaveItems();

    GetWorldTimerManager().SetTimer(
        WaveTimerHandle,
        this,
        &AAMyGameMode::NextWave,
        RemainingTime,
        false
    );
}

void AAMyGameMode::NextWave()
{
    CurrentWave++;

    StartWave();
}

FVector AAMyGameMode::GetRandomSpawnLocation() const
{
    return FVector(
        FMath::FRandRange(SpawnMin.X, SpawnMax.X),
        FMath::FRandRange(SpawnMin.Y, SpawnMax.Y),
        FMath::FRandRange(SpawnMin.Z, SpawnMax.Z)
    );
}

void AAMyGameMode::SpawnWaveItems()
{
    for (int32 i = 0; i < CoinCount; i++)
    {
        FVector SpawnLocation = GetRandomSpawnLocation();

        GetWorld()->SpawnActor<ACoin>(
            CoinClass,
            SpawnLocation,
            FRotator::ZeroRotator
        );
    }
}