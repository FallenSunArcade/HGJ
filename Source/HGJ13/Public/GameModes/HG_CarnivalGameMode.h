// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HG_CarnivalGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSpeakingDelegate, float, DialogueIndex);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEntranceDelegate);

class AHG_PlayerController;
class UHG_GameInstance;
class AHG_BaseCharacter;
class AHG_ShootingBooth;
class AHG_WoM;
class UHG_DialogComponent;
class AHG_WhackAMole;

UCLASS()
class HGJ13_API AHG_CarnivalGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AHG_CarnivalGameMode();
	
	virtual void BeginPlay() override;

	void SetupShootingBooth();

	void EnableShootingBooth();

	void EnableShootingBoothCharacter(const FString& Name);

	void EnableWoMShootingBooth();

	void EnableWomWhackAMole();

	void EnableWackAMole();

	void SetupWackAMole();

	void SetupDunkBooth();

	void SetupFerrisWheel();

	void SetPlayerStart(const FString& StartTag);

	void AddShootingBoothCharacter(AHG_BaseCharacter* Spawner, FString Name);

	void SetShootingBooth(AHG_ShootingBooth* Booth) { ShootingBooth = Booth;}

	AHG_ShootingBooth* GetShootingBooth() const { return ShootingBooth;}

	void SetWomShootingBooth(AHG_WoM* W) { WoMShootingBooth = W;}

	void SetWomWhackAMole(AHG_WoM* W) { WoMWhackAMole = W;}

	void SetWhackAMole(AHG_WhackAMole* MoleGame) { WhackAMole = MoleGame;}

	AHG_WhackAMole* GetWhackAMole() const { return WhackAMole;}
	
	UPROPERTY(BlueprintAssignable)
	FSpeakingDelegate SpeakingDelegate;
	
	UFUNCTION(BlueprintImplementableEvent)
	void Speaking(float Index);

	UFUNCTION()
	void StartEntranceDialog();

private:
	UPROPERTY(EditAnywhere)
	UHG_DialogComponent* EntranceDialogComponent;
	
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

	UPROPERTY()
	AHG_ShootingBooth* ShootingBooth;

	UPROPERTY()
	AHG_WhackAMole* WhackAMole;

	UPROPERTY()
	AHG_WoM* WoMShootingBooth;

	UPROPERTY()
	AHG_WoM* WoMWhackAMole;

	FTimerHandle EntranceDelayHandle;
};


