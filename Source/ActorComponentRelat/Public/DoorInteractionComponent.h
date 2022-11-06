// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DoorInteractionComponent.generated.h"
//#include "Curves/CurveFloat.h" // Smothing like animation of the door might required somthing much complex. 
							   // It specefy The rate of teh door to be open 


class ATriggerBox; // There is a class called a trigger box
 

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ACTORCOMPONENTRELAT_API UDoorInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorInteractionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
		FRotator DesiredRotation = FRotator::ZeroRotator; // U need to se them at zero to avoid Garbage value 
		FRotator StartRotation = FRotator::ZeroRotator;
		FRotator FinalRotation = FRotator::ZeroRotator;
	
	UPROPERTY(EditAnywhere)
		float TimeToRotate = 1.0f;
		float CurrentRotationTime = 0.0; 

	UPROPERTY(EditAnywhere)
		ATriggerBox* TriggerBox; 

	UPROPERTY(EditAnywhere)
		FRuntimeFloatCurve OpenCurve; 
		
};
