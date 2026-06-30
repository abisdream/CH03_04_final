// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AItem.h"
#include "LandMine.generated.h"

UCLASS()
class CH03_API ALandMine : public AAItem
{
	GENERATED_BODY()

public:

	ALandMine();

	virtual void Interact(AActor* Interactor) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine")
	float Damage = 30.f;
};
