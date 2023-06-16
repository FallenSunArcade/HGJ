// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/HG_PlayerController.h"
#include "Characters/HG_BaseCharacter.h"
#include "Components/HG_DialogComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ToolBox/HG_LogCategories.h"


AHG_PlayerController::AHG_PlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AHG_PlayerController::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHG_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if(InputComponent)
	{
		InputComponent->BindAction("Interact", IE_Pressed, this, &AHG_PlayerController::Interact);
	}
}

void AHG_PlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHG_PlayerController::Interact()
{
	FVector Location;
	FRotator Rotation;
	GetPlayerViewPoint(Location, Rotation);
	FVector End = Location + Rotation.Vector() * 200;
	
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	FHitResult Hit;

	DrawDebugLine(GetWorld(), Location, End, FColor::Red, true);
	if(GetWorld()->LineTraceSingleByChannel(Hit, Location, End, ECC_GameTraceChannel1, Params))
	{
		
		if (UHG_DialogComponent* DialogComponent =
			Cast<UHG_DialogComponent>(Hit.GetActor()->GetComponentByClass(UHG_DialogComponent::StaticClass())))
		{
			DialogComponent->OnInteraction_Implementation();
		}
	}
}

