// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "GameInstances/HG_GameInstance.h"
#include "HG_SetDialogSection.generated.h"

/**
 * 
 */
UCLASS()
class HGJ13_API UHG_SetDialogSection : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	UPROPERTY(EditAnywhere)
	EDialogSections DialogSection;
};
