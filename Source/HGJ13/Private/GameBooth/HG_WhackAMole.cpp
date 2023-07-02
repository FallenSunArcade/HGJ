// Fill out your copyright notice in the Description page of Project Settings.


#include "GameBooth/HG_WhackAMole.h"
#include "GameModes/HG_CarnivalGameMode.h"
#include "Kismet/GameplayStatics.h"


AHG_WhackAMole::AHG_WhackAMole()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AHG_WhackAMole::TargetHit(bool Head)
{
	if(Head)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red,
			FString::Printf(TEXT("Hit a head.")));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red,
		FString::Printf(TEXT("Hit a mole.")));
	}
	
}

void AHG_WhackAMole::BeginPlay()
{
	Super::BeginPlay();

	AHG_CarnivalGameMode* GameMode = Cast<AHG_CarnivalGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	check(GameMode);
	GameMode->SetWhackAMole(this);
}
