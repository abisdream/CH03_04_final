


#include "HealthPotion.h"
#include "APawnTest.h"

AHealthPotion::AHealthPotion()
{

}

void AHealthPotion::Interact(AActor* Interactor)
{
    Super::Interact(Interactor);

    AAPawnTest* Player = Cast<AAPawnTest>(Interactor);

    if (!Player)
    {
        return;
    }

    Player->AddHealth(HealAmount);

    DestroyItem();
}

