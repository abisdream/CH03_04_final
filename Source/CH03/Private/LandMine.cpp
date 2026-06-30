

#include "LandMine.h"
#include "APawnTest.h"

ALandMine::ALandMine()
{

}

void ALandMine::Interact(AActor* Interactor)
{
    Super::Interact(Interactor);

    AAPawnTest* Player = Cast<AAPawnTest>(Interactor);

    if (!Player)
    {
        return;
    }

    Player->TakeDamage(Damage);

    DestroyItem();
}