// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveActor.h"

// Sets default values
AMoveActor::AMoveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

    StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMeshComp->SetupAttachment(SceneRoot);

    StaticMeshComp->SetRelativeLocation(FVector(0.f, 0.f, 50.f));

    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));

    if (MeshAsset.Succeeded())
    {
        StaticMeshComp->SetStaticMesh(MeshAsset.Object);
    }

    MoveSpeed = 100.f;
    MaxRange = 300.f;
    Direction = 1.0f;
    MoveDirection = FVector(1.f, 0.f, 0.f);
    bIsPaused = false;
    PauseTimer = 0.f;
    StopTime = 2.f;

}
// Called every frame
void AMoveActor::Tick(float DeltaTime)
{
    
    if (bIsPaused)
    {
        PauseTimer += DeltaTime;

        if (PauseTimer >= StopTime)
        {
            bIsPaused = false;
            PauseTimer = 0.f;
        }

        return;
    }

    FVector CurrentLocation = GetActorLocation();

    CurrentLocation += MoveSpeed * DeltaTime * Direction * MoveDirection;

   
    if (Direction > 0)
    {
        if (FVector::Dist(CurrentLocation, StartLocation) >= MaxRange)
        {
            CurrentLocation = StartLocation + MoveDirection * MaxRange;

            Direction *= -1.0f;
            bIsPaused = true;
        }
    }
    else
    {
        if (FVector::Dist(CurrentLocation, StartLocation) <= MoveSpeed * DeltaTime)
        {
            Direction *= -1.0f;
            bIsPaused = true;
        }
    }
    SetActorLocation(CurrentLocation, true);
}

void AMoveActor::BeginPlay()
{
    Super::BeginPlay();

    StartLocation = GetActorLocation();
}