// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameInstances/HG_GameInstance.h"
#include "HG_Spawner.generated.h"

class AHG_BaseCharacter;

UCLASS()
class HGJ13_API AHG_Spawner : public AActor
{
	GENERATED_BODY()

public:
	AHG_Spawner();
	
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Spawner")
	TSubclassOf<AHG_BaseCharacter> CharacterClass;

	UPROPERTY(EditAnywhere, Category = "Spawner")
	FString CharacterName = TEXT("");
	
	UPROPERTY(EditAnywhere, Category = "Spawner")
	EGameStates CurrentLevel = EGameStates::ShootingBooth;
	
};
