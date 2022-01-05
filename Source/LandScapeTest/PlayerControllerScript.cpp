// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllerScript.h"

// Sets default values
APlayerControllerScript::APlayerControllerScript()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	bUseControllerRotationYaw = false;

	cam = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	cam->AttachTo(RootComponent);
	cam->SetRelativeLocation(FVector(0, 0, 40));
		
}

// Called when the game starts or when spawned
void APlayerControllerScript::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerControllerScript::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerControllerScript::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("MoveLeft", this, &APlayerControllerScript::horizontalMovement);
	InputComponent->BindAxis("MoveForward", this, &APlayerControllerScript::verticalMovement);
	InputComponent->BindAxis("MouseX", this, &APlayerControllerScript::horizontalRotation);
	InputComponent->BindAxis("MouseY", this, &APlayerControllerScript::verticalRotation);
}

void APlayerControllerScript::horizontalMovement(float value)
{
	if (value) {
		AddMovementInput(GetActorRightVector(), value);
	}
}

void APlayerControllerScript::verticalMovement(float value)
{
	if (value)
	{
		AddMovementInput(GetActorForwardVector(), value);
	}
}

void APlayerControllerScript::horizontalRotation(float value)
{
	AddActorLocalRotation(FRotator(0, value, 0));
}

void APlayerControllerScript::verticalRotation(float value)
{
	if (value)
	{
		float temp = cam->GetRelativeRotation().Pitch + value;
		if (temp<65 && temp >-65)
		{
			cam->AddLocalRotation(FRotator(value, 0, 0));
		}
	}
}



