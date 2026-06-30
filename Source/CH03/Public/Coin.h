

#pragma once

#include "CoreMinimal.h"
#include "AItem.h"
#include "Coin.generated.h"


UCLASS()
class CH03_API ACoin : public AAItem
{
	GENERATED_BODY()
	

public :
	ACoin();
	virtual void Interact(AActor* Interactor) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Coin")
	int32 CoinValue = 1;
};
