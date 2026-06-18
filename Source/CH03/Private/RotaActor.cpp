// Fill out your copyright notice in the Description page of Project Settings.


#include "RotaActor.h"

// Sets default values
ARotaActor::ARotaActor()
{

    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

    StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMeshComp->SetupAttachment(SceneRoot);

    StaticMeshComp->SetRelativeLocation(FVector(0.f, 0.f, 0.f));

    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));

    if (MeshAsset.Succeeded())
    {
        StaticMeshComp->SetStaticMesh(MeshAsset.Object);
    }

    PrimaryActorTick.bCanEverTick = true;
        
    //StopAngle = 45.f;
    StopAnglePitch = 0.f;
    StopAngleYaw = 0.f;
    StopAngleRoll = 0.f;

    //StopTime = 0.f;
    StopTimePitch = 0.f;
    StopTimeYaw = 0.f;
    StopTimeRoll = 0.f;

    NextStopYaw = StopAngleYaw;
    NextStopPitch = StopAnglePitch;
    NextStopRoll = StopAngleRoll;
                    
    PauseTimer = 0.f;

    PitchSpeed = 0.f;
    YawSpeed = 0.f;
    RollSpeed = 0.f;

    bPitchPaused = false;
    bYawPaused = false;
    bRollPaused = false;

}

void ARotaActor::HandleAxis( //회전 통제 함수
    float& Value, float Speed, float& Nextstop,float StopAngle,float StopTime ,float& Timer, bool& bPaused, float DeltaTime)
{
    if (bPaused)//회전조건
    {
        Timer += DeltaTime;
        if (Timer >= StopTime)
        {
            bPaused = false;
            Timer = 0.f;
        }
        return;
    }

    float Delta = Speed * DeltaTime;

    bool bReached((Speed > 0 && Value + Delta >= Nextstop) || (Speed < 0 && Value + Delta <= Nextstop));

    if(bReached)
    {
        Value = Nextstop;
        Nextstop += StopAngle;
       
        bPaused = true;
        return;

    }

    Value += Delta;
}


void ARotaActor::Tick(float DeltaTime)
{
       
               
    // 회전 관리 구역
    
    HandleAxis(Pitch, PitchSpeed, NextStopPitch, StopAnglePitch, StopTimePitch, PitchTimer, bPitchPaused, DeltaTime);
    HandleAxis(Yaw, YawSpeed, NextStopYaw, StopAngleYaw, StopTimeYaw, YawTimer, bYawPaused, DeltaTime);
    HandleAxis(Roll, RollSpeed, NextStopRoll, StopAngleRoll, StopTimeRoll, RollTimer, bRollPaused, DeltaTime);
            
    SetActorRotation(FRotator(Pitch,Yaw,Roll));
}




