// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask/HG_Transition.h"
#include "Kismet/GameplayStatics.h"
#include "Controllers/HG_PlayerController.h"

EBTNodeResult::Type UHG_Transition::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AHG_PlayerController* PlayerController = Cast<AHG_PlayerController>( UGameplayStatics::GetPlayerController(GetWorld(), 0));
	check(PlayerController);

	PlayerController->MakeTransition();
	
	return EBTNodeResult::Succeeded;
}
