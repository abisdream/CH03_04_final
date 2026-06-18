// Fill out your copyright notice in the Description page of Project Settings.


#include "AMyGameMode.h"
#include "APawnTest.h"
#include "TestPlayerController.h"


AAMyGameMode::AAMyGameMode()
{
    DefaultPawnClass = AAPawnTest::StaticClass();
    PlayerControllerClass = ATestPlayerController::StaticClass();
}