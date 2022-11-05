// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCorneActor.h"

// Sets default values
AMyCorneActor::AMyCorneActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCorneActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCorneActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();

	CurrentLocation = CurrentLocation + CorneVelocity * DeltaTime;

	SetActorLocation(CurrentLocation);

	float DistancedMoved = FVector::Dist(StartLocation, CurrentLocation);

	if (DistancedMoved > MoveDistance)
	{
		CorneVelocity = -CorneVelocity;
		StartLocation = CurrentLocation;

	}


}

