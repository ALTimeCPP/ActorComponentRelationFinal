// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorInteractionComponent.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UDoorInteractionComponent::UDoorInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorInteractionComponent::BeginPlay()
{
	Super::BeginPlay();
	//FRotator DesiredRotation(0.0f, 90.0f, 0.0f);// remember here it uses Degrees unreal uses cm // our Desired Rotation
	StartRotation = GetOwner()->GetActorRotation(); // Desired rotation - Our Current Rotation assume our current location is zero same as our delta rotation.
	FinalRotation = GetOwner()->GetActorRotation() + DesiredRotation;// CURRENT ROTATION WHICH ASSUEM IS ZERO + 90 DEGREE (OUR CURRENT LOCATION) 
	
	//Ensure TimeRotation is greaterthan Epsilon
	CurrentRotationTime = 0.0f; 
	
}


// Called every frame
void UDoorInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//FRotator CurrentRotation = GetOwner()->GetActorRotation();
	if (CurrentRotationTime < TimeToRotate)
	{
		CurrentRotationTime += DeltaTime;
		const float RotationAlpha = FMath::Clamp(CurrentRotationTime / TimeToRotate, 0.0f, 1.0f); // Time per frame second
		const FRotator CurrentRotation = FMath::Lerp(StartRotation, FinalRotation, RotationAlpha);
		
		GetOwner()->SetActorRotation(CurrentRotation); 

	}
	
	
}

