

#include "AItem.h"


AAItem::AAItem()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(RootComponent);

	Sphere->OnComponentBeginOverlap.AddDynamic(this,&AAItem::OnItemOverlap);
	Sphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Sphere->SetCollisionResponseToAllChannels(ECR_Ignore);
	Sphere->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	


}


void AAItem::BeginPlay()
{
	Super::BeginPlay();
	
	Sphere->SetSphereRadius(PickupRadius);
}


void AAItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAItem::Interact(AActor* Interactor)
{
	UE_LOG(LogTemp, Warning, TEXT("Base Item Interact"));

	if (!Interactor)
	{
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("%s Interacted!"), *Interactor->GetName());

	
}

void AAItem::OnItemOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap!!"));
	Interact(OtherActor);
}

void AAItem::DestroyItem()
{
	Destroy();
}