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
void UDoorControl::BeginPlay(){
	Super::BeginPlay();


	owner = GetOwner();					//This will set the owner to the door for manipulation
	if (!pressurePlate) { 
		UE_LOG(LogTemp, Warning, TEXT("pressure plate missing")); 
	}//
	
}//begin play

float UDoorControl::ActorsOnPlate(){
	float totMass = 0.f;
	//find overlapping actors
	TArray<AActor*> triggers;

	if (!pressurePlate) { return 0; }/// this will help prevent the game crashing due to nullpointers

	pressurePlate->GetOverlappingActors(OUT triggers);
	// iterate through the array
	for (auto& tmp : triggers) {
		totMass += tmp->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		///UE_LOG(LogTemp, Warning, TEXT("%s on the plate"), *tmp->GetName());
	}

	return totMass;
}//actors on plate


// Called every frame
void UDoorControl::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// if the trigger (the player) steps into the trigger volume area make something happen..
	if (ActorsOnPlate() > goalMass) {
		//use the blueprint to open the door for us  
		onOpen.Broadcast();
	}else{
		onClose.Broadcast();
	}

	
}//tick

