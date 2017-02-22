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


	Owner = GetOwner();														//This will set the owner to the door for manipulation
	TheTrigger = GetWorld()->GetFirstPlayerController()->GetPawn();			//the following will make the character a trigger
	
}


void UDoorControl::OpenDoor() {
	//Open the door... 
	//next set the rotation using FRotator.
	Owner->SetActorRotation(FRotator(0.f, -theAngle, 0.f));
}//open door

void UDoorControl::CloseDoor() {
	//Close the door... 
	//next set the rotation using FRotator to close it again.
	Owner->SetActorRotation(FRotator(0.f, 0.f, 0.f));
}//close door







// Called every frame
void UDoorControl::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// if the trigger (the player) steps into the trigger volume area make something happen..
	if (PressurePlate->IsOverlappingActor(TheTrigger)) {
		OpenDoor();	//call the open door function...
		lastOpened = GetWorld()->GetTimeSeconds();
	}//if
	if(GetWorld()->GetTimeSeconds() - lastOpened > closeDelay){
		CloseDoor();
	}

	
}//tick

