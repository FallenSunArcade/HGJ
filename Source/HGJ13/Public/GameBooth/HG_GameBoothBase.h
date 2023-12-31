﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HG_GameBoothBase.generated.h"

UENUM(BlueprintType)
enum class ERounds : uint8 {
	Round1,
	Round2,
	Round3
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRoundStartDelegate, int32, RoundNumber);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRoundOverDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGameOverDelegate, bool, Won);

class UHG_DialogComponent;
class UHG_GameBoard;
class UHG_ScoreTime;

UCLASS()
class HGJ13_API AHG_GameBoothBase : public AActor
{
	GENERATED_BODY()

public:
	AHG_GameBoothBase();
	
	virtual void BeginPlay() override;

	FRoundStartDelegate RoundStartDelegate;
	
	FRoundOverDelegate RoundOverDelegate;
	
	FGameOverDelegate GameOverDelegate;

	UFUNCTION(BlueprintImplementableEvent)
	void RoundStart(int32 RoundNumber);

	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool Won);
	
protected:
	UPROPERTY(EditAnywhere)
	UHG_DialogComponent* DialogComponent;
	
	UPROPERTY(EditAnywhere, Category = "Interaction")
	UHG_GameBoard* ScoreBoard;

	UPROPERTY(EditAnywhere, Category = "Game Booth")
	bool bHasTickets = false;
	
	UPROPERTY(EditAnywhere, Category = "Game Booth")
	ERounds CurrentRound = ERounds::Round1;

	UPROPERTY(EditAnywhere, Category = "Game Booth")
	TSubclassOf<UHG_ScoreTime> ScoreTimeClass;
};
