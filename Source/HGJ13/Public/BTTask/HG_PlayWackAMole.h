// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "HG_PlayWackAMole.generated.h"

/**
 * 
 */
UCLASS()
class HGJ13_API UHG_PlayWackAMole : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UFUNCTION()
	void GameOver(bool Won);
	
private:
	UPROPERTY()
	UBehaviorTreeComponent* BTComponent = nullptr;
};
