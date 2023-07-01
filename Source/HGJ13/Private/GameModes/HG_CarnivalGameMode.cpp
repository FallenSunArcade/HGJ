// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/HG_CarnivalGameMode.h"
#include "Characters/HG_BaseCharacter.h"
#include "Controllers/HG_PlayerController.h"
#include "GameFramework/Character.h"
#include "GameInstances/HG_GameInstance.h"
#include "Interfaces/HG_Interactable.h"
#include "GameBooth/HG_ShootingBooth.h"
#include "Kismet/GameplayStatics.h"
#include "Actors/HG_WoM.h"
#include "Components/HG_DialogComponent.h"
#include "GameBooth/HG_WhackAMole.h"


AHG_CarnivalGameMode::AHG_CarnivalGameMode()
{
	PrimaryActorTick.bCanEverTick = false;
	EntranceDialogComponent = CreateDefaultSubobject<UHG_DialogComponent>(TEXT("Dialog Component"));
}

void AHG_CarnivalGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	SpeakingDelegate.AddDynamic(this, &AHG_CarnivalGameMode::Speaking);
	
	PlayerControllerRef = Cast<AHG_PlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	check(PlayerControllerRef);

	GameInstanceRef = Cast<UHG_GameInstance>(GetGameInstance());
	check(GameInstanceRef);
	
	switch(GameInstanceRef->GetGameState())
	{
	case EGameStates::ShootingBooth:
		SetupShootingBooth();
		break;
	case EGameStates::DreamWorld1: 
		break;
	case EGameStates::WhackAMole:
		SetupWackAMole();
		break;
	case EGameStates::DreamWorld2:
		break;
	case EGameStates::DunkTank:
		SetupDunkBooth();
		break;
	case EGameStates::DreamWorld3:
		break;
	case EGameStates::FerrisWheel:
		SetupFerrisWheel();
		break;
	case EGameStates::DreamWorld4:
		break;
	default:
		break;
	}
}

void AHG_CarnivalGameMode::SetupShootingBooth()
{
	SetPlayerStart(TEXT("ShootingBooth"));

	GetWorldTimerManager().SetTimer(EntranceDelayHandle, this, &AHG_CarnivalGameMode::StartEntranceDialog, .1f, false);
	
	if(ShootingBoothCharacters.Find("Mom"))
	{
		if (IHG_Interactable* InteractionComponent =
		Cast<IHG_Interactable>(ShootingBoothCharacters["Mom"]->FindComponentByInterface(UHG_Interactable::StaticClass())))
		{
			InteractionComponent->SetInteractionVisibility_Implementation(true);
		}
	}
}

void AHG_CarnivalGameMode::EnableShootingBooth()
{
	if(ShootingBooth)
	{
		if (IHG_Interactable* InteractionComponent =
			Cast<IHG_Interactable>(ShootingBooth->FindComponentByInterface(UHG_Interactable::StaticClass())))
		{
			InteractionComponent->SetInteractionVisibility_Implementation(true);
		}
	}
}

void AHG_CarnivalGameMode::EnableShootingBoothCharacter(const FString& Name)
{
}

void AHG_CarnivalGameMode::EnableWoMShootingBooth()
{
	if(WoMShootingBooth)
	{
		if (IHG_Interactable* InteractionComponent =
			Cast<IHG_Interactable>(WoMShootingBooth->FindComponentByInterface(UHG_Interactable::StaticClass())))
		{
			InteractionComponent->SetInteractionVisibility_Implementation(true);
		}
	}
}

void AHG_CarnivalGameMode::EnableWomWhackAMole()
{
	if(WoMWhackAMole)
	{
		if (IHG_Interactable* InteractionComponent =
			Cast<IHG_Interactable>(WoMWhackAMole->FindComponentByInterface(UHG_Interactable::StaticClass())))
		{
			InteractionComponent->SetInteractionVisibility_Implementation(true);
		}
	}
}

void AHG_CarnivalGameMode::EnableWackAMole()
{
	if(WhackAMole)
	{
		if (IHG_Interactable* InteractionComponent =
			Cast<IHG_Interactable>(WhackAMole->FindComponentByInterface(UHG_Interactable::StaticClass())))
		{
			InteractionComponent->SetInteractionVisibility_Implementation(true);
		}
	}
}

void AHG_CarnivalGameMode::SetupWackAMole()
{
	SetPlayerStart(TEXT("WhackAMole"));
}

void AHG_CarnivalGameMode::SetupDunkBooth()
{
	SetPlayerStart(TEXT("DunkBooth"));
}

void AHG_CarnivalGameMode::SetupFerrisWheel()
{
	SetPlayerStart(TEXT("FerrisWheel"));
}

void AHG_CarnivalGameMode::SetPlayerStart(const FString& StartTag)
{
	if(const AActor* PlayerStart = FindPlayerStart(PlayerControllerRef, StartTag))
	{
		ACharacter* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

			Player->SetActorTransform(PlayerStart->GetTransform());
	}
}

void AHG_CarnivalGameMode::AddShootingBoothCharacter(AHG_BaseCharacter* Spawner, FString Name)
{
	ShootingBoothCharacters.Emplace(Name, Spawner);
}

void AHG_CarnivalGameMode::StartEntranceDialog()
{
	EntranceDialogComponent->SetCanInteract(true);
	EntranceDialogComponent->OnInteraction_Implementation(PlayerControllerRef);
	EntranceDialogComponent->SetCanInteract(false);
}


