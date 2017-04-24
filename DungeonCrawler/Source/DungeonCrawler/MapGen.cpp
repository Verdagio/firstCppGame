// Fill out your copyright notice in the Description page of Project Settings.

#include "DungeonCrawler.h"
#include "MapGen.h"


// Sets default values
AMapGen::AMapGen()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> FloorMesh(TEXT("StaticMesh'/Game/StarterContent/Architecture/Floor_400x400.Floor_400x400'"));
	Floor->SetStaticMesh(FloorMesh);
}

// Called when the game starts or when spawned
void AMapGen::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMapGen::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AMapGen::MapGenerate() {
	int MaxX = 32;
	int MaxY = 32;
	int TileSize = 400;
	FVector MyVec;

	for (int row = 0; row < MaxX; row++) {
		MyVec.X = TileSize * row;
		for (int col = 0; col < MaxY; col++) {
			MyVec.Y = TileSize * col;
			Floor->AddInstance(FTransform(MyVec));
		}		
	}
	

}
