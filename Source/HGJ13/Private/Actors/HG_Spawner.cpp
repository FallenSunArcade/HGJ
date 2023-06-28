// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/HG_Spawner.h"
#include "Characters/HG_BaseCharacter.h"
#include "GameModes/HG_CarnivalGameMode.h"
#include "Kismet/GameplayStatics.h" 


AHG_Spawner::AHG_Spawner()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AHG_Spawner::BeginPlay()
{
	Super::BeginPlay();

	const UHG_GameInstance* GameInstanceRef = Cast<UHG_GameInstance>(GetGameInstance());
	check(GameInstanceRef);

	if(CurrentLevel == GameInstanceRef->GetGameState())
	{
		if(AHG_CarnivalGameMode* GameMode = Cast<AHG_CarnivalGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
		{
			AHG_BaseCharacter* CharacterRef = GetWorld()->SpawnActor<AHG_BaseCharacter>(CharacterClass, GetActorTransform());
			check(CharacterRef);
			GameMode->AddShootingBoothCharacter(CharacterRef, CharacterName);
		}
	}

}

