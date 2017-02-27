// Fill out your copyright notice in the Description page of Project Settings.

#include "DungeonCrawler.h"
#include "Grab.h"


// Sets default values for this component's properties
UGrab::UGrab()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrab::BeginPlay()
{
	Super::BeginPlay();

	// ...
	UE_LOG(LogTemp, Warning, TEXT("The Grabber is active!"));
	
}


// Called every frame
void UGrab::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// Actor position this tick
	AActor* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	FVector LTE = Player->GetActorLocation() + (Player->GetActorRotation().Vector() * Reach);
	
	
	

	//log the player position and rotation
	//UE_LOG(LogTemp, Warning, TEXT(" Location: %s	Rotation: %s"), *Player->GetActorLocation().ToString(), *Player->GetActorRotation().ToString());

	//Show the grab line for debugging
	DrawDebugLine(GetWorld(), Player->GetActorLocation(), LTE, FColor(255, 125, 50), false, 0.f, 0.f, 5.f);
	/// Query Params
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());

	///Ray cast out to reach distance
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(OUT Hit, Player->GetActorLocation(), LTE, FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), TraceParams);

	AActor* ActorHit = Hit.GetActor();
	if (ActorHit) {
		UE_LOG(LogTemp, Warning, TEXT("HIT: %s"), *(ActorHit->GetName()));
	}
	
}

