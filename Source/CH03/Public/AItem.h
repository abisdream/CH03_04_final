

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"


#include "AItem.generated.h"

UCLASS()
class CH03_API AAItem : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	
	AAItem();

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* Sphere;

	UFUNCTION()
	void OnItemOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	float PickupRadius = 100.f;


public:	
	
	virtual void Tick(float DeltaTime) override;
	virtual void Interact(AActor* Interactor) override;
	void DestroyItem();
};
