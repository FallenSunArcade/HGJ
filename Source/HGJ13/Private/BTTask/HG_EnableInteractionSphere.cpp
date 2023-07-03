// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask\HG_EnableInteractionSphere.h"
#include "GameModes/HG_CarnivalGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Actors/HG_InteractionSphere.h"

EBTNodeResult::Type UHG_EnableInteractionSphere::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if(AHG_CarnivalGameMode* GameMode = Cast<AHG_CarnivalGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
	{
		GameMode->EnableInteractionSphere(EInteractionSphere);
	}
	return EBTNodeResult::Succeeded;
}
