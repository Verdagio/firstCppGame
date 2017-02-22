// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS(Blueprintable)	//this allows us to access from blueprint 
class DUNGEONCRAWLER_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//health property (Can be read & written in blueprint)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Character")
		float Health = 100;

	//calculate current health func (can only be read in blueprint not modified)
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Base Character")
		bool isAlive = true;

	// isAlive property
	virtual void CheckIsAlive();

	//death function  (callable creates a node witin' blueprint)
	UFUNCTION(BlueprintCallable, Category = "Base Character")
		virtual void CheckHealth(float f);

#if WITH_EDITOR		//Only changable within' editor, whenever changes are made code will be run in response to changes
	//Editor based code for properties management
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropEvent) //will notify of property changes
		override;
#endif
};
