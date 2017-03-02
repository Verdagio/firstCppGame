// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "DoorControl.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);// Creates a dynamic multi-cast delegate. Allows the Blueprint to handle the operation

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUNGEONCRAWLER_API UDoorControl : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorControl();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	//returns float value of the mass 
	float ActorsOnPlate();

	UPROPERTY(BlueprintAssignable)
		FDoorEvent onOpen;

	UPROPERTY(BlueprintAssignable)
		FDoorEvent onClose;

private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume* pressurePlate = nullptr; 

	UPROPERTY(EditAnywhere)
		float goalMass = 30.f;
	UPROPERTY(EditAnywhere)
		float theAngle = -90.f;
	UPROPERTY(EditAnywhere)
		float closeDelay = 1.f;
		float lastOpened;

	UPROPERTY(VisibleAnywhere)
		
		AActor* owner = nullptr;
		
	
};
