// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask/HG_PlayWackAMole.h"
#include "GameBooth/HG_WhackAMole.h"
#include "GameModes/HG_CarnivalGameMode.h"
#include "Kismet/GameplayStatics.h"

EBTNodeResult::Type UHG_PlayWackAMole::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	BTComponent = &OwnerComp;
	
	if(const AHG_CarnivalGameMode* GameMode = Cast<AHG_CarnivalGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
	{
		AHG_WhackAMole* WhackAMole = GameMode->GetWhackAMole();

		check(WhackAMole);

		WhackAMole->RoundStartDelegate.Broadcast(0);

		GetWorld()->GetTimerManager().SetTimer(GameTimerHandle, this, &UHG_PlayWackAMole::GameOver, 30.f);
	}                 

	return EBTNodeResult::InProgress;
}

void UHG_PlayWackAMole::GameOver()
{
	if(const AHG_CarnivalGameMode* GameMode = Cast<AHG_CarnivalGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
	{
		AHG_WhackAMole* WhackAMole = GameMode->GetWhackAMole();

		check(WhackAMole);

		WhackAMole->RoundOverDelegate.Broadcast();
		
	}

	FinishLatentTask(*BTComponent, EBTNodeResult::Succeeded);
}
