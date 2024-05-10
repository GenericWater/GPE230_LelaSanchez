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

	// GPE230 Module 2 - Lecture 6.1 Damage Management

	// initialize _currentHealth to the value from the details tab when game starts
	_currentHealth = maxHealth; // sets health at beginning of game
	
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


// GPE230 Module 2 - Lecture 6.1 Damage Management

/// <summary>
/// Apply incoming damage to health and check if the player was killed.
/// </summary>
/// <param name="DamageAmount">The Amount of damage to be subtracted from current health. </param>
/// <param name="DamageEvent"></param>
/// <param name="EventInstigator"></param>
/// <param name="DamageCauser"></param>
/// <returns>The amount of damage taken.</returns>



// needed to add "struct" before FDamageAmount
float AMazeCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	// Subtract incoming damage
	_currentHealth -= DamageAmount; // -= is an operator that sets the first operand to its current value minus the value of the 2nd operand

	// Debug printout - prints to the Output Log at bottom of Unreal
	UE_LOG(LogTemp, Log, TEXT("Player took %f damage. %f health remaining."), DamageAmount, _currentHealth); //%f is a placeholder for float variables

	// Check if player has died
	if (_currentHealth <= 0)
		Die();

	return DamageAmount;
}

/// <summary>
/// Stop player from moving, trigger game over status, and prompt player to restart the level.
/// </summary>

void AMazeCharacter::Die()
{
	// CAN ADD: Death animation

	// Prevent player from moving
	moveSpeed = 0;
	rotationSpeed = 0;

	//TODO: Trigger game over state and prompt player to restart level
}

