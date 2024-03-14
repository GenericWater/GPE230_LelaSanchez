// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "LockAndKey.generated.h"

/**
 * Header files establish function and variable names, scripts uses these.
 */
UCLASS()
class GPE230_LELASANCHEZ_API ALockAndKey : public ATriggerBox
{
	GENERATED_BODY()

	// Lecture 1.6: Locks and Keys 
public:
	// ALockAndKey(); Constructor - runs whenever a new instance of this class is created
	ALockAndKey();

	UFUNCTION()
		// CheckActorType() will run anytime an actor enters this trigger
		// will be connected to TriggerBox::OnActorBeginOverlap -> auto runs on overlap
		void CheckActorType(class AActor* OverlappedActor, class AActor* OtherActor);

	UFUNCTION()
		// OpenTheDoor(); will "pick up" the key and "open" the corresponding door by destroying both
		// Only called if OtherActor from ChackActorType() is our MazeCharacter
		void OpenTheDoor();
protected:
	virtual void BeginPlay() override;
	
};
