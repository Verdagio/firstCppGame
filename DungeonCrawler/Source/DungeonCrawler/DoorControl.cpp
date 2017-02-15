// Fill out your copyright notice in the Description page of Project Settings.

#include "DungeonCrawler.h"
#include "DoorControl.h"


// Sets default values for this component's properties
UDoorControl::UDoorControl()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorControl::BeginPlay()
{
	Super::BeginPlay();

	//the following will make the character a trigger
	
	TheTrigger = GetWorld()->GetFirstPlayerController()->GetPawn();
	
}


void UDoorControl::OpenDoor() {
	//Open the door... need to find the owner first
	AActor* Owner = GetOwner();
	//next set the rotation
	Owner->SetActorRotation(FRotator(0.f, 125.f, 0.f));
}






// Called every frame
void UDoorControl::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// if the trigger steps into the trigger volume area make something happen..
	if (PressurePlate->IsOverlappingActor(TheTrigger)) {
		OpenDoor();	//call the open door function...
	}
}

