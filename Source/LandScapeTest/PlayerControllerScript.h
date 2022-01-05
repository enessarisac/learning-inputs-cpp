// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "PlayerControllerScript.generated.h"

UCLASS()
class LANDSCAPETEST_API APlayerControllerScript : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerControllerScript();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void horizontalMovement(float value);
	void verticalMovement(float value);
	void horizontalRotation(float value);
	void verticalRotation(float value);
	UPROPERTY(EditAnywhere, Category = "Camera")
		UCameraComponent* cam;
};
