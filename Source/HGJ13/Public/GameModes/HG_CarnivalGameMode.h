// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HG_CarnivalGameMode.generated.h"

class AHG_PlayerController;
class UHG_GameInstance;
class AHG_BaseCharacter;

UCLASS()
class HGJ13_API AHG_CarnivalGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AHG_CarnivalGameMode();
	
	virtual void BeginPlay() override;

	void SetupShootingBooth();

	void SetupWackAMole();

	void SetupDunkBooth();

	void SetupFerrisWheel();

	void SetPlayerStart(const FString& StartTag);

	void AddShootingBoothCharacter(AHG_BaseCharacter* Spawner, FString Name);

private:
	UPROPERTY()
	AHG_PlayerController* PlayerControllerRef;

	UPROPERTY()
	UHG_GameInstance* GameInstanceRef;

	UPROPERTY()
	TMap<FString, AHG_BaseCharacter*> ShootingBoothCharacters;

	UPROPERTY()
	TMap<FString, AHG_BaseCharacter*> WhackAMoleCharacters;

	UPROPERTY()
	TMap<FString, AHG_BaseCharacter*> DunkBoothCharacters;

	UPROPERTY()
	TMap<FString, AHG_BaseCharacter*> FerrisWheelCharacters;
};


