// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyCorneActor.generated.h"

UCLASS()
class ACTORCOMPONENTRELAT_API AMyCorneActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyCorneActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, Category = "Moving Corne Transform")
		FVector CorneVelocity = FVector(100, 0, 0);

	UPROPERTY(VisibleAnywhere, Category = "Moving Corne Transform")
		
		float MoveDistance = 100; ;
	
	    FVector StartLocation; 


};
