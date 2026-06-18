// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "MoveActor.generated.h"

UCLASS()
class CH03_API AMoveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoveActor();
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

protected:
	
	UPROPERTY(VisibleAnywhere)
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMeshComp;

	FVector StartLocation;//초기 위치

	UPROPERTY(Editanywhere, BlueprintReadWrite, Category = "Move")
	float MoveSpeed;//속도
	UPROPERTY(Editanywhere, BlueprintReadWrite, Category = "Move")
	float MaxRange;//반복 거리
	
	float Direction;//반향성
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
	FVector MoveDirection;

	UPROPERTY()
	bool bIsPaused;
	UPROPERTY()
	float PauseTimer;
	UPROPERTY(Editanywhere, BlueprintReadWrite, Category = "Move")
	float StopTime;

};
