// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MazeCharacter.generated.h"

UCLASS()
class GPE230_LELASANCHEZ_API AMazeCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMazeCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

// Lecture 1.5: Cameras and Movement
private:
	UPROPERTY(EditAnywhere)
		float moveSpeed;
	UPROPERTY(EditAnywhere)
		float rotationSpeed;
private:
	void MoveFB(float value);
	void MoveLR(float value);
	void Rotate(float value);

	// Jump implimentation
	void CheckJump();

	UPROPERTY()
	bool jumping;

// GPE230 Module 2 - Lecture 6.1 Damage Management
	// Health system implimentation
public:
	/// <summary>
	/// The maximum starting health for this character
	/// </summary>
	UPROPERTY(EditAnywhere) // EditAnywhere property allows modification of the variable in the Details tab
	float maxHealth;

protected:
	/// <summary>
	/// The current health of this character
	/// </summary>
	float _currentHealth;

protected:
	// Called when the game starts or when spawned
	
	virtual void BeginPlay() override;
	//virtual void BeginPlay();
	

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	virtual void Die();
};
