// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeGameMode.h"
// Lecture 1.5:
void AMazeGameMode::InitGameState()
{
	// Super refers to our header file or parent class
	// Super::InitGameState(); will call InitGameState() in MazeGameMode.h
	Super::InitGameState();

	// If there is no override for the default pawn class...
	if (DefaultPawnClass == ADefaultPawn::StaticClass())
		// DefaultPawnClass is from Unreal's GameMode class > default player pawn @ spawn
		// ADefaultPawn is the parent for the default pawn class
	{
		// set the default pawn to MY pawn in place of Unreal's default!
		DefaultPawnClass = DefaultPlayerCharacter;
		// DefaultPlayerCharacter; is the variable we made in MazeGameMode.h
	}
}