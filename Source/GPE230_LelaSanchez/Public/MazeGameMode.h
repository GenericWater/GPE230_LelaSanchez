#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

// Lecture 1.5 Slide 31 importation of headers
#include "GameFramework/DefaultPawn.h" // Lets us access and change the default pawn that player spawn as
#include "MazeCharacter.h" // Lets us access and change info from MazeCharacter C++ Class

// .generated.h needs to be last include in include list*****************************
#include "MazeGameMode.generated.h"


/**
 * 
 */
UCLASS()
class GPE230_LELASANCHEZ_API AMazeGameMode : public AGameModeBase
{
	GENERATED_BODY()

public: // InitGameState() function to initialize our game
	void InitGameState() override;

private: // Variabel to hold our custom default character
	// UPROPERTY modifies the variable that follows it
	UPROPERTY(EditAnywhere, NoClear) // EditAnywhere modifies the private variable in the Blueprint
		// NoClear prevents the variable from becoming null / empty

	// TSubclassOf<AMazeCharacter> | T stands for data type 
	// TSubclassOf<SomeType> is a variable that can only hold that data type and derived classes - inheritance
	// Can even hold our AMazeCharacterBP!!!
	TSubclassOf<AMazeCharacter> DefaultPlayerCharacter = AMazeCharacter::StaticClass();
	// AMazeCharacter::StaticClass(); represents the base class @ runtime 
};

// Fill out your copyright notice in the Description page of Project Settings.