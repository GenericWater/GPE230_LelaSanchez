// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeCharacter.h"

// Sets default values
AMazeCharacter::AMazeCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// set jumping to false on start / load
	jumping = false;
}

// Called when the game starts or when spawned
void AMazeCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMazeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Jumping
	if (jumping)
	{
		Jump(); // Uses UE5's default Jump function to jump
	}

}

// Lecture 1.5: Cameras and Movement

// called to bind functionality to input on load!!!
void AMazeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// bind functions to input events
	PlayerInputComponent->BindAxis("MoveFB", this, &AMazeCharacter::MoveFB);
	PlayerInputComponent->BindAxis("MoveLR", this, &AMazeCharacter::MoveLR);
	PlayerInputComponent->BindAxis("Rotate", this, &AMazeCharacter::Rotate);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMazeCharacter::CheckJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMazeCharacter::CheckJump);
}

// AddMovementInput and AddControllerYawInput are character functions
// AddMovementInput() takes a direction and speed then moves the character.
// AddControllerYawInput() takes a speed and rotates the Character that way
void AMazeCharacter::MoveFB(float value)
{
	AddMovementInput(GetActorForwardVector(), value * moveSpeed);
}

void AMazeCharacter::MoveLR(float value)
{
	AddMovementInput(-GetActorRightVector(), value * moveSpeed);
}

void AMazeCharacter::Rotate(float value)
{
	AddControllerYawInput(value * rotationSpeed);
}

// Custom Jump function created down here

void AMazeCharacter::CheckJump()
{
	if (jumping)
	{
		jumping = false;
	}
	else
	{
		jumping = true;
	}
}

