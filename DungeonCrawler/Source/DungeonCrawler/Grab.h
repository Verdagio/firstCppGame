// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Grab.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUNGEONCRAWLER_API UGrab : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrab();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:
	//The distance of the reach (in cm)
	float Reach = 100.f;
	
	UPhysicsHandleComponent* physicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;


	// ray cast & grab whats in reach
	void Grabbed();
	
	// called when grabbed is released
	void Released();

	// Find attached components
	void FindComponents();

	// Hit for first physics body in reach
	const FHitResult GetFirstBodyReached();


};
