// Fill out your copyright notice in the Description page of Project Settings.


#include "GameBooth/HG_WhackAMole.h"
#include "GameModes/HG_CarnivalGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Components/HG_GameBoard.h"


AHG_WhackAMole::AHG_WhackAMole()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AHG_WhackAMole::TargetHit(bool Head)
{
	++CurrentScore;
	ScoreBoard->SetScore(CurrentScore);
}

void AHG_WhackAMole::StartRound()
{
	ScoreBoard->SetScore(0);
	ScoreBoard->SetTime(MaxRoundTime);

	RoundTime = MaxRoundTime;
	NumTargets = 10;

	GetWorldTimerManager().SetTimer(RoundTimerHandle, this, &AHG_WhackAMole::RoundTick, 1.f, true, 1.f);
}

void AHG_WhackAMole::RoundTick()
{
	--RoundTime;
	
	ScoreBoard->SetTime(RoundTime);

	if(RoundTime <= 0)
	{
		GetWorldTimerManager().ClearTimer(RoundTimerHandle);

		if(CurrentScore > 13)
		{
			GameOverDelegate.Broadcast(true);
		}
		else
		{
			GameOverDelegate.Broadcast(false);
		}
	}
}

void AHG_WhackAMole::BeginPlay()
{
	Super::BeginPlay();

	AHG_CarnivalGameMode* GameMode = Cast<AHG_CarnivalGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	check(GameMode);
	GameMode->SetWhackAMole(this);

	ScoreBoard->SetScore(13);
}
