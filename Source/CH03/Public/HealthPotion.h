

#pragma once

#include "CoreMinimal.h"
#include "AItem.h"
#include "HealthPotion.generated.h"

UCLASS()
class CH03_API AHealthPotion : public AAItem
{
	GENERATED_BODY()
	

public:

	AHealthPotion();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Potion")
	float HealAmount = 30.f;

	virtual void Interact(AActor* Interactor) override;
};


