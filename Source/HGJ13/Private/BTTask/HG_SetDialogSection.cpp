// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask/HG_SetDialogSection.h"
#include "Kismet/GameplayStatics.h"

EBTNodeResult::Type UHG_SetDialogSection::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if(UHG_GameInstance* GameInstance = Cast<UHG_GameInstance>(UGameplayStatics::GetGameInstance(GetWorld())))
	{
		check(GameInstance);
		GameInstance->SetCurrentDialogSection(DialogSection);
	}
	return EBTNodeResult::Succeeded;
}
