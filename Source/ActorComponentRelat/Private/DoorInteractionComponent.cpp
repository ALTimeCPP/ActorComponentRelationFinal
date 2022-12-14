// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorInteractionComponent.h"
#include "Math/UnrealMathUtility.h"
#include"GameFramework/Actor.h" 
#include "GameFramework/PlayerController.h" // 
#include "Engine/TriggerBox.h" 
// Firas added those without indicating in lecture !!
#include "Engine/World.h" // why we needed this. 
#include "Kismet/GameplayStatics.h"
#include "Sound\SoundCue.h"





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
	CurrentRotationTime = 0.0f;
	
	//UGameplayStatics::PlaySoundAtLocation(this, DoorSound, GetActorLocation());
	 // Otherside Rotation
	StartRotationOtherside = GetOwner()->GetActorRotation();
	FinalRotationOtherside = GetOwner()->GetActorRotation() + DesiredRotationOtherside;
	//Ensure TimeRotation is greaterthan Epsilon
	CurrentRotationTimeOtherside = 0.0f;
	

	// Closed Prameters
	StartRotationClosed = GetOwner()->GetActorRotation();
	FinalRotationClosed = GetOwner()->GetActorRotation() + DesiredRotationClosed;
	CurrentRotationTimeClosed = 0.0f; 
	//OnActorBeginOverlap.AddDynamic(this, &UDoorInteractionComponent::OnOverlapBegin);
	//OnActorEndOverlap.AddDynamic(this, &UDoorInteractionComponent::OnOverlapEnd);
	
}


// Called every frame
void UDoorInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//FRotator CurrentRotation = GetOwner()->GetActorRotation();
	if (CurrentRotationTime < TimeToRotate) // First check  the Rotation then we dont need to do any of this 
	{
		APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
		// Check if the Trigger Box is valid and Get world ( we set this up so that work only on Local player
		if (TriggerBox && GetWorld() && GetWorld()->GetFirstLocalPlayerFromController())
		{
			// We check the player Pawn 

			// And we check if the player pawn is indeed inside the box

			if (PlayerPawn)
			{ // Then we apply the logic which we have done it previous. 
				CurrentRotationTime += DeltaTime;
				// We will be useing Time ratio which we were useing as time Alpha
				const float TimeRatio = FMath::Clamp(CurrentRotationTime / TimeToRotate, 0.0f, 1.0f);
				// We will use this to get value from the curve
				const float RotationAlpha = OpenCurve.GetRichCurveConst()->Eval(TimeRatio);
				const FRotator CurrentRotation = FMath::Lerp(StartRotation, FinalRotation, RotationAlpha);

				GetOwner()->SetActorRotation(CurrentRotation);
				//UGameplayStatics::PlaySoundAtLocation(this, DoorSound, GetActorLocation());
				UE_LOG(LogTemp, Warning, TEXT("wARNING"));
			}
		}

	}
}

void UDoorInteractionComponent::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
}

void UDoorInteractionComponent::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
}
	
	


