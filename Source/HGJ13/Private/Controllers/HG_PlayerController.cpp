// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/HG_PlayerController.h"
#include "Characters/HG_BaseCharacter.h"
#include "Components/HG_DialogComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ToolBox/HG_LogCategories.h"
#include "UI/HG_HudOverlay.h"



AHG_PlayerController::AHG_PlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AHG_PlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	const FInputModeGameOnly InputModeGameOnly;
	SetInputMode(InputModeGameOnly);
	SetShowMouseCursor(false);
	
	if(*HudWidgetClass)
	{
		HudOverlay = CreateWidget<UHG_HudOverlay>(this, HudWidgetClass);

		if(HudOverlay)
		{
			HudOverlay->AddToViewport();
			HudOverlay->SetVisibility(ESlateVisibility::Visible);
			HudOverlay->StartGameTransition();
		}
	}
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
	
	if(GetWorld()->LineTraceSingleByChannel(Hit, Location, End, ECC_GameTraceChannel1, Params))
	{
		if (IHG_Interactable* InteractionComponent =
			Cast<IHG_Interactable>(Hit.GetActor()->FindComponentByInterface(UHG_Interactable::StaticClass())))
		{
			InteractionComponent->OnInteraction_Implementation(this);
		}
	}
}

