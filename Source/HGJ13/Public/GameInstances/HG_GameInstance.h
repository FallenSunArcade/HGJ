// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "HG_GameInstance.generated.h"

UENUM(BlueprintType)
enum class EGameStates : uint8 {
	ShootingBooth,
	DreamWorld1,
	WhackAMole,
	DreamWorld2,
	DunkTank,
	DreamWorld3,
	FerrisWheel,
	DreamWorld4
};

UCLASS()
class HGJ13_API UHG_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	EGameStates GetGameState() const {return CurrentState;}

	UFUNCTION(BlueprintCallable)
    void SetGameState(EGameStates NewState) {CurrentState = NewState;}
	
private:
	UPROPERTY(EditAnywhere, Category = "Game")
	EGameStates CurrentState = EGameStates::ShootingBooth;
};
