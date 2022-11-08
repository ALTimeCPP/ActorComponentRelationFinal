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
	// OtherSide Rotation
	UPROPERTY(EditAnywhere, Category = "TimrOtherSide")
		FRotator DesiredRotationOtherside = FRotator::ZeroRotator; // U need to se them at zero to avoid Garbage value 
		FRotator StartRotationOtherside = FRotator::ZeroRotator;
		FRotator FinalRotationOtherside = FRotator::ZeroRotator;
	// Close the door 
	UPROPERTY(EditAnywhere, Category = "TimrOtherSide")
		FRotator DesiredRotationClosed = FRotator::ZeroRotator; // U need to se them at zero to avoid Garbage value 
		FRotator StartRotationClosed = FRotator::ZeroRotator;
		FRotator FinalRotationClosed = FRotator::ZeroRotator;
	
	UPROPERTY(EditAnywhere)
		float TimeToRotate = 1.0f;
		float CurrentRotationTime = 0.0; 
	
	// Otherside Parameters 
	UPROPERTY(EditAnywhere, Category = "TimrOtherSide")
		float TimeToRotateOtherside = 1.0f;
		float CurrentRotationTimeOtherside = 0.0;

	// Closed Door
	UPROPERTY(EditAnywhere, Category = "TimrOtherClosed")
		float TimeToRotateClosed = 1.0f;
		float CurrentRotationTimeClosed = 0.0;
		// overlap begin function
	UFUNCTION()
		void OnOverlapBegin( AActor* OverlappedActor,  AActor* OtherActor);

		// overlap end function
	UFUNCTION()
		void OnOverlapEnd(AActor* OverlappedActor,  AActor* OtherActor);

	UPROPERTY(EditAnywhere)
		ATriggerBox* TriggerBox; 
	

	UPROPERTY(EditAnywhere)
		FRuntimeFloatCurve OpenCurve; 
	

	UPROPERTY(EditAnywhere, Category = "Door SoundOtherside")
		class USoundBase* DoorSound; 
		
};
