// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask/HG_EnableInteraction.h"
#include "GameModes/HG_CarnivalGameMode.h"
#include "Kismet/GameplayStatics.h"

EBTNodeResult::Type UHG_EnableInteraction::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if(AHG_CarnivalGameMode* GameMode = Cast<AHG_CarnivalGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
	{
		switch(Interactable)
		{
		case EInteractable::ShootingBooth:
			{
				GameMode->EnableShootingBooth();
				break;
			}
		case EInteractable::WoMShootingBooth:
			{
				GameMode->EnableWoMShootingBooth();
				break;
			}
		case EInteractable::InteractionSphereMole:
			{
				GameMode->EnableWoMShootingBooth();
				break;
			}
		case EInteractable::WackAMole:
			{
				GameMode->EnableWackAMole();
				break;
			}
		case EInteractable::WoMWackAMole:
			{
				GameMode->EnableWomWhackAMole();
				break;
			}
		case EInteractable::DunkBooth:
			{
				break;
			}
		case EInteractable::FerrisWheel:
			{
				break;
			}
		}
	}
	return EBTNodeResult::Succeeded;
}
