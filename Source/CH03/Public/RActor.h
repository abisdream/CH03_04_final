// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RActor.generated.h"

UCLASS()
class CH03_API ARActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARActor();

protected:
	
	UPROPERTY()
	USceneComponent* SceneRoot;

	UPROPERTY()
	UStaticMeshComponent* StaticMeshCom;


};
