
#include "APawnTest.h"
#include "Components/CapsuleComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


// Sets default values
AAPawnTest::AAPawnTest()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Box;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Box);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(Box);
	SpringArm->bUsePawnControlRotation = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = false;

}

// Called when the game starts or when spawned
void AAPawnTest::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (ULocalPlayer* LocalPlayer = PC->GetLocalPlayer())
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
			{
				Subsystem->AddMappingContext(IMC_Player, 0);
			}
		}
	}
	
}

// Called every frame
void AAPawnTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bBoost)
	{
		CurrentSpeed = FMath::FInterpTo(CurrentSpeed,MaxSpeed,DeltaTime,AccelerationSpeed);
	}
	else
	{
		CurrentSpeed = FMath::FInterpTo(CurrentSpeed, NormalSpeed, DeltaTime, AccelerationSpeed);
	}

}

// Called to bind functionality to input
void AAPawnTest::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (EnhancedInput)
	{
		EnhancedInput->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AAPawnTest::Move);

		EnhancedInput->BindAction(IA_Look, ETriggerEvent::Triggered, this, &AAPawnTest::Look);

		EnhancedInput->BindAction(IA_UpDown, ETriggerEvent::Triggered, this, &AAPawnTest::UpDown);

		EnhancedInput->BindAction(IA_Roll, ETriggerEvent::Triggered, this, &AAPawnTest::Roll);

		EnhancedInput->BindAction(IA_Boost, ETriggerEvent::Started, this, &AAPawnTest::BoostStart);

		EnhancedInput->BindAction(IA_Boost, ETriggerEvent::Completed, this, &AAPawnTest::BoostEnd);
	}

}

void AAPawnTest::Move(const FInputActionValue& Value)
{
	FVector2D InputValue = Value.Get<FVector2D>();

	//UE_LOG(LogTemp, Warning, TEXT("X=%f Y=%f"),InputValue.X,InputValue.Y);

	//FVector MoveDirection = GetActorForwardVector() * InputValue.Y + GetActorRightVector() * InputValue.X;
	FVector LocalMove(InputValue.Y, InputValue.X, 0.f);
	//AddActorWorldOffset(MoveDirection*MoveSpeed*GetWorld()->GetDeltaSeconds(),true);
	AddActorLocalOffset(LocalMove* CurrentSpeed *GetWorld()->GetDeltaSeconds(),true);
}

void AAPawnTest::Look(const FInputActionValue& Value)
{
	FVector2D InputValue = Value.Get<FVector2D>();

	float DeltaTime = GetWorld()->GetDeltaSeconds();

	//UE_LOG(LogTemp, Warning, TEXT("Look X=%f Y=%f"),InputValue.X,InputValue.Y);
	//Yaw
	AddActorLocalRotation(FRotator(
		-InputValue.Y * RotationSpeed * DeltaTime, // Pitch
		InputValue.X * RotationSpeed * DeltaTime, // Yaw
		0.f                                      // Roll
	));
	
	//CurrentPitch += InputValue.Y * RotationSpeed * DeltaTime;

	//CurrentPitch = FMath::Clamp(CurrentPitch,-80.f,80.f);

	//SpringArm->SetRelativeRotation(FRotator(-CurrentPitch,0.f,0.f));
}

void AAPawnTest::UpDown(const FInputActionValue& Value)
{
	float InputValue = Value.Get<float>();

	//UE_LOG(LogTemp, Warning, TEXT("UpDown = %f"), InputValue);

	FVector LocalMove(0.f, 0.f, InputValue);

	AddActorLocalOffset(LocalMove* MoveSpeed *GetWorld()->GetDeltaSeconds(),true);

}

void AAPawnTest::Roll(const FInputActionValue& Value)
{
	float RollValue = Value.Get<float>();

	//UE_LOG(LogTemp, Warning, TEXT("Roll = %f"), RollValue);

	float DeltaTime = GetWorld()->GetDeltaSeconds();

	AddActorLocalRotation(FRotator(0.f,0.f,RollValue*RotationSpeed*DeltaTime));
}

void AAPawnTest::BoostStart(const FInputActionValue& Value)
{
	bBoost = true;
}

void AAPawnTest::BoostEnd(const FInputActionValue& Value)
{
	bBoost = false;
}