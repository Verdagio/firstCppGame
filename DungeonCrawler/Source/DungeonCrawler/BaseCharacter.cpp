// Fill out your copyright notice in the Description page of Project Settings.

#include "DungeonCrawler.h"
#include "BaseCharacter.h"


// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// health related stuff
void ABaseCharacter::CheckHealth(float F) {
	Health += F;
	CheckIsAlive();
}//check health

//is the character alive?
void ABaseCharacter::CheckIsAlive() {
	if (Health <= 0) {
		isAlive = false;
	} else {
		isAlive = true;
	}//if else
}//check is alive

// post edit change property
#if WITH_EDITOR
void ABaseCharacter::PostEditChangeProperty(FPropertyChangedEvent& PropEvent) {
	isAlive = true;
	Health = 100;
	Super::PostEditChangeProperty(PropEvent);

	CheckIsAlive();
}


#endif