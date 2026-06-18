// Fill out your copyright notice in the Description page of Project Settings.


#include "RActor.h"

// Sets default values
ARActor::ARActor()
{
    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

    StaticMeshCom = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMeshCom->SetupAttachment(SceneRoot);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(
        TEXT("/Engine/BasicShapes/Cube.Cube")
    );

    if (MeshAsset.Succeeded())
    {
        StaticMeshCom->SetStaticMesh(MeshAsset.Object);
    }

    static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Script/Engine.Material'/Game/BarkWillow/Material/M_Bark_Willow.M_Bark_Willow'"));

    if (MaterialAsset.Succeeded())
    {
        StaticMeshCom->SetMaterial(0, MaterialAsset.Object);
    }

}
