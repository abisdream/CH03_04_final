

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h"


UINTERFACE(MinimalAPI)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};


class CH03_API IInteractable
{
	GENERATED_BODY()

public:
	// 여기에 Interact 함수 선언
	virtual void Interact(AActor* Interactor) = 0;
};
