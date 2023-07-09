// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask/HG_SetModeToUI.h"

#include "Controllers/HG_PlayerController.h"
#include "Kismet/GameplayStatics.h"

EBTNodeResult::Type UHG_SetModeToUI::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AHG_PlayerController* PlayerController = Cast<AHG_PlayerController>( UGameplayStatics::GetPlayerController(GetWorld(), 0));
	check(PlayerController);

	FInputModeUIOnly InputModeUIOnly;
	InputModeUIOnly.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
	PlayerController->SetInputMode(InputModeUIOnly);
	PlayerController->SetShowMouseCursor(true);
	return EBTNodeResult::Succeeded;
}
