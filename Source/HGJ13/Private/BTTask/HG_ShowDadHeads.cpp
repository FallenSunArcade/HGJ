// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask/HG_ShowDadHeads.h"

#include "GameBooth/HG_ShootingBooth.h"
#include "GameModes/HG_CarnivalGameMode.h"
#include "Kismet/GameplayStatics.h"

EBTNodeResult::Type UHG_ShowDadHeads::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if(const AHG_CarnivalGameMode* GameMode = Cast<AHG_CarnivalGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
	{
		AHG_ShootingBooth* ShootingBooth = GameMode->GetShootingBooth();
		check(ShootingBooth);
		ShootingBooth->SetupTargets(5.f, true);
	}
	
	return EBTNodeResult::Succeeded;
}
