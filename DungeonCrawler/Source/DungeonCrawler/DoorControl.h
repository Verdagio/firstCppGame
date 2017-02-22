// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "DoorControl.generated.h"


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

	void OpenDoor();
	void CloseDoor();


private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate; 
	UPROPERTY(EditAnywhere)
		float theAngle = -90.f;
	UPROPERTY(EditAnywhere)
		float closeDelay = 1.f;
		float lastOpened;

	UPROPERTY(VisibleAnywhere)
		AActor* TheTrigger;
		AActor* Owner;
		
	
};
