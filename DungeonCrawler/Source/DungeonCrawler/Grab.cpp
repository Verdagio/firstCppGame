// Fill out your copyright notice in the Description page of Project Settings.

#include "DungeonCrawler.h"
#include "Grab.h"

#define OUT

// Sets default values for this component's properties
UGrab::UGrab()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}///constructor


// Called when the game starts
void UGrab::BeginPlay()
{
	Super::BeginPlay();
	FindComponents();



}///begin play

// Called every frame
void UGrab::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	AActor* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	FVector LTE = Player->GetActorLocation() + (Player->GetActorRotation().Vector() * Reach);///line trace end
	if (!physicsHandle) { return; }/// this will help prevent the game crashing due to nullpointers
	// If the handle is attached
	if (physicsHandle->GrabbedComponent)
	{
		physicsHandle->SetTargetLocation(LTE);
	}
		// move the object being held




}///tick component

// Looks for components and verifies that they are attached to the relevant object.
void UGrab::FindComponents() {

	/// Look for the attached Input component
	physicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (physicsHandle) {
		UE_LOG(LogTemp, Warning, TEXT("physics handle component found"), *GetOwner()->GetName());

	} else {
		UE_LOG(LogTemp, Error, TEXT("%s missing physics handle"), *GetOwner()->GetName());
	}///if else if

	/// Look for the attached Input component
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent) {
		UE_LOG(LogTemp, Warning, TEXT("Input component found"), *GetOwner()->GetName());
		///Bind action
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrab::Grabbed);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrab::Released);
	} else {
		UE_LOG(LogTemp, Error, TEXT("%s missing input component"), *GetOwner()->GetName());
	}///if else if
}

///Find components

 // Used to pick up or grab items using either the E key or right face button on a controller
void UGrab::Grabbed() {
	//UE_LOG(LogTemp, Warning, TEXT("Grabbed pressed!"));
	
	///Line trace and check if reach actors w/ physics body collision channel set
	auto HitRes = GetFirstBodyReached();
	auto ObjToGrab = HitRes.GetComponent();
	auto ActorHit = HitRes.GetActor();

	if (!physicsHandle) { return; }/// this will help prevent the game crashing due to nullpointers
	///if we hit somethinf then attach physics handel
	if (ActorHit != nullptr){
		physicsHandle->GrabComponentAtLocation(ObjToGrab, NAME_None, ObjToGrab->GetOwner()->GetActorLocation());
	}


}///grabbed method used for picking up items

// called when either the E key or right face button on a controller is released
void UGrab::Released() {
	UE_LOG(LogTemp, Warning, TEXT("Grabbed released!"));

	if (!physicsHandle) { return; }//

	physicsHandle->ReleaseComponent();
}///released function used to release items that have been grabbed#

// Get the player position, ray-cast in front of the player, check for a hit & return FHitResult (The object that was hit)
const FHitResult UGrab::GetFirstBodyReached() {


	// Actor position 
	AActor* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	FVector LTE = Player->GetActorLocation() + (Player->GetActorRotation().Vector() * Reach);///line trace end
	/*///log the player position and rotation
	UE_LOG(LogTemp, Warning, TEXT(" Location: %s	Rotation: %s"), *Player->GetActorLocation().ToString(), *Player->GetActorRotation().ToString());

	///Display a debugging line of the reach of our character
	DrawDebugLine(GetWorld(), Player->GetActorLocation(), LTE, FColor(255, 125, 50), false, 0.f, 0.f, 5.f);
	/// Query Params*/
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());

	///Ray cast out to reach distance
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(OUT Hit, Player->GetActorLocation(), LTE, FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), TraceParams);

	AActor* ActorHit = Hit.GetActor();
	if (ActorHit) {
		UE_LOG(LogTemp, Warning, TEXT("HIT: %s"), *(ActorHit->GetName()));
	}

	return Hit;
}





