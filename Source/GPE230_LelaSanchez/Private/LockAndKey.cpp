// Fill out your copyright notice in the Description page of Project Settings.

#include "LockAndKey.h"

#include "MazeCharacter.h" // need this to refrence AMazeCharacter / custom class
#include "MazeGameMode.h" // trying to troubleshoot

// Lecture 1.6: Locks and Keys 
ALockAndKey::ALockAndKey()
{

}

void ALockAndKey::CheckActorType(AActor* OverlappedActor, AActor* OtherActor) // Called when any actor enters our trigger
{
	//UE_LOG(LogTemp, Log, TEXT("Verify AMazeCharacter - CheckActorType"));

	// If the other actor is a maze character 
	if (OtherActor->IsA(AMazeCharacter::StaticClass()))
		OpenTheDoor();
}

void ALockAndKey::OpenTheDoor()
{
	//UE_LOG(LogTemp, Log, TEXT("Door is open - OpenTheDoor"));

	// Can add animations for door and key destroying
	
	//Opens door and removes the key by destroying parent object
	this->Destroy(); // Destroyes both key and door 
}

void ALockAndKey::BeginPlay()
{
	Super::BeginPlay(); // Had to be added to ensure the lock and key would be destroyed on pickup

	//UE_LOG(LogTemp, Log, TEXT("Door is locked - BeginPlay"));

	// this - first parameter is object the trigger is on - any instance of this class
	OnActorBeginOverlap.AddDynamic(this, &ALockAndKey::CheckActorType);
	// custom CheckActorType() function will run when anything overlaps our key's trigger volume
}
