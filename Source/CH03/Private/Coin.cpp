// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin.h"
#include "APawnTest.h"

ACoin::ACoin()
{

}



void ACoin::Interact(AActor* Interactor)
{
    Super::Interact(Interactor);

    UE_LOG(LogTemp, Warning, TEXT("Coin Get!"));

    AAPawnTest* Player = Cast<AAPawnTest>(Interactor);

    if (!Player)
    {
        return;
    }

    Player->AddCoin(CoinValue);

    DestroyItem();
}