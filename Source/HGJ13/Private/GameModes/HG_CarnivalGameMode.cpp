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
#include "Actors/HG_InteractionSphere.h"


AHG_CarnivalGameMode::AHG_CarnivalGameMode()
{
	PrimaryActorTick.bCanEverTick = false;
	EntranceDialogComponent1 = CreateDefaultSubobject<UHG_DialogComponent>(TEXT("Booth1"));
	EntranceDialogComponent2 = CreateDefaultSubobject<UHG_DialogComponent>(TEXT("Booth2"));
	EntranceDialogComponent3 = CreateDefaultSubobject<UHG_DialogComponent>(TEXT("Booth3"));
	EntranceDialogComponent4 = CreateDefaultSubobject<UHG_DialogComponent>(TEXT("Booth4"));
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

void AHG_CarnivalGameMode::EnableSceneCharacter(const FString& Name)
{
	if(SceneCharacters.Find(Name))
	{
		if (IHG_Interactable* InteractionComponent =
		Cast<IHG_Interactable>(SceneCharacters[Name]->FindComponentByInterface(UHG_Interactable::StaticClass())))
		{
			InteractionComponent->SetInteractionVisibility_Implementation(true);
		}
	}
}

void AHG_CarnivalGameMode::EnableInteractionSphere(const EInteractionSphere& Sphere)
{
	if(InteractionSpheres.Find(Sphere))
	{
		if (IHG_Interactable* InteractionComponent =
Cast<IHG_Interactable>(InteractionSpheres[Sphere]->FindComponentByInterface(UHG_Interactable::StaticClass())))
		{
			InteractionComponent->SetInteractionVisibility_Implementation(true);
		}
	}
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
	GetWorldTimerManager().SetTimer(EntranceDelayHandle, this, &AHG_CarnivalGameMode::StartEntranceDialog2, .1f, false);
}

void AHG_CarnivalGameMode::SetupDunkBooth()
{
	SetPlayerStart(TEXT("DunkBooth"));
	GetWorldTimerManager().SetTimer(EntranceDelayHandle, this, &AHG_CarnivalGameMode::StartEntranceDialog3, .1f, false);
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

void AHG_CarnivalGameMode::AddSceneCharacter(AHG_BaseCharacter* Spawner, FString Name)
{
	SceneCharacters.Emplace(Name, Spawner);
}

void AHG_CarnivalGameMode::AddInteractionSphere(AHG_InteractionSphere* Sphere, const EInteractionSphere& Type)
{
	InteractionSpheres.Emplace(Type, Sphere);
}

void AHG_CarnivalGameMode::StartEntranceDialog()
{
	EntranceDialogComponent1->SetCanInteract(true);
	EntranceDialogComponent1->OnInteraction_Implementation(PlayerControllerRef);
	EntranceDialogComponent1->SetCanInteract(false);
}

void AHG_CarnivalGameMode::StartEntranceDialog2()
{
	EntranceDialogComponent2->SetCanInteract(true);
	EntranceDialogComponent2->OnInteraction_Implementation(PlayerControllerRef);
	EntranceDialogComponent2->SetCanInteract(false);
}

void AHG_CarnivalGameMode::StartEntranceDialog3()
{
	EntranceDialogComponent3->SetCanInteract(true);
	EntranceDialogComponent3->OnInteraction_Implementation(PlayerControllerRef);
	EntranceDialogComponent3->SetCanInteract(false);
}

void AHG_CarnivalGameMode::StartEntranceDialog4()
{
	EntranceDialogComponent4->SetCanInteract(true);
	EntranceDialogComponent4->OnInteraction_Implementation(PlayerControllerRef);
	EntranceDialogComponent4->SetCanInteract(false);
}


