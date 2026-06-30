// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "TimerManager.h"



#include "AMyGameMode.generated.h"


UCLASS()
class CH03_API AAMyGameMode : public AGameMode
{
	GENERATED_BODY()

	
public:

	AAMyGameMode();

    void StartWave();
    void NextWave();
    void SpawnWaveItems();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Wave")
    int32 CurrentWave = 1;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
    int32 CurrentLevel = 1;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Wave")
    float RemainingTime = 30.f;

    FTimerHandle WaveTimerHandle;

    virtual void BeginPlay() override;
    //스폰아이템
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave")
    int32 CoinCount = 5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave")
    int32 PotionCount = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave")
    int32 MineCount = 2;

};


