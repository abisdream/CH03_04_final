// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

#include "RotaActor.generated.h"


UCLASS()
class CH03_API ARotaActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARotaActor();

	virtual void Tick(float DeltaTime) override;

protected:

	UPROPERTY(VisibleAnywhere)
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMeshComp;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float StopAngle;//멈춘 각도*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float StopAnglePitch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float StopAngleYaw;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float StopAngleRoll;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	//float StopTime;//멈춘 시간
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float StopTimePitch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float StopTimeYaw;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float StopTimeRoll;


	//멈춤상태 체크
	UPROPERTY()
	bool bIsPaused;//제거할것
	UPROPERTY()
	bool bPitchPaused;
	UPROPERTY()
	bool bYawPaused;
	UPROPERTY()
	bool bRollPaused;



	//멈춘 시간 타이머
	UPROPERTY()
	float PauseTimer;//제거용
	UPROPERTY()
	float PitchTimer;
	UPROPERTY()
	float YawTimer;
	UPROPERTY()
	float RollTimer;

	


	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	//FRotator RotationRate;//회전 속도와 방향
	UPROPERTY()
	FRotator PreviousAngle;//이전 각도
	UPROPERTY()
	FRotator CurrentAngle;//현재 각도

	//X,Y,Z축 멈추는각
	
	float NextStopPitch;
	
	float NextStopYaw;
	
	float NextStopRoll;

	//XYZ값
	
	float Pitch;
	
	float Yaw;
	
	float Roll;

	//XYZ속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float PitchSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float YawSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float RollSpeed;
	

	void HandleAxis(
		float& Value, float Speed, float& Nextstop,float StopAngle,float StopTime ,float& Timer, bool& bPaused, float DeltaTime);



};
