// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "InputActionValue.h"
#include "InputMappingContext.h"
#include "InputAction.h"

#include "APawnTest.generated.h"

class UBoxComponent;
class USkeletalMeshComponent;
class USpringArmComponent;
class UCameraComponent;

class UInputMappingContext;
class UInputAction;

UCLASS()
class CH03_API AAPawnTest : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAPawnTest();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void AddCoin(int32 Value);
	void AddHealth(float Value);
	//데미지와 죽음
	void TakeDamage(float Damage);
	void Die();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* Box;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* IMC_Player;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* IA_Move;

	UPROPERTY(EditAnywhere, Category = "Move")
	float MoveSpeed = 500.0f;

	UPROPERTY(EditAnywhere, Category = "Look")
	float RotationSpeed = 100.0f;
	UPROPERTY(EditAnywhere, Category = "Look")
	float CurrentPitch = 0.f;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* IA_Look;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* IA_UpDown;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* IA_Roll;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* IA_Boost;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float NormalSpeed = 1400.f; // 약 50km/h

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MaxSpeed = 5556.f; // 약 200km/h

	UPROPERTY(EditAnywhere, Category = "Movement")
	float AccelerationSpeed = 5.f;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void UpDown(const FInputActionValue& Value);
	void Roll(const FInputActionValue& Value);
	void BoostStart(const FInputActionValue& Value);
	void BoostEnd(const FInputActionValue& Value);

	float CurrentSpeed = 1400.f;

	bool bBoost = false;

	//아이템
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
	int32 Coin = 0;
	//체력
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player|Stat")
	float MaxHealth = 100.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player|Stat")
	float Health = 100.f;

	

};
