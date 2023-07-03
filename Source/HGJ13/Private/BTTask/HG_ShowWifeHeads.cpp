// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask/HG_ShowWifeHeads.h"
#include "GameModes/HG_CarnivalGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "GameBooth/HG_WhackAMole.h"

EBTNodeResult::Type UHG_ShowWifeHeads::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if(const AHG_CarnivalGameMode* GameMode = Cast<AHG_CarnivalGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
	{
		AHG_WhackAMole* WhackAMole = GameMode->GetWhackAMole();
		check(WhackAMole);
		WhackAMole->RoundStartDelegate.Broadcast(0);
	}
	
	return EBTNodeResult::Succeeded;
}
