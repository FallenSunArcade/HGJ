// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask/HG_EnableCharacter.h"
#include "GameModes/HG_CarnivalGameMode.h"
#include "Kismet/GameplayStatics.h"

EBTNodeResult::Type UHG_EnableCharacter::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if(AHG_CarnivalGameMode* GameMode = Cast<AHG_CarnivalGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
	{
		GameMode->EnableSceneCharacter(CharacterName);
	}
	return EBTNodeResult::Succeeded;
}
