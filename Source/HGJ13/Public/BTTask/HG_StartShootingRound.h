// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "HG_StartShootingRound.generated.h"


UCLASS()
class HGJ13_API UHG_StartShootingRound : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UFUNCTION()
	void RoundOver(bool Won);

private:
	UPROPERTY()
	UBehaviorTreeComponent* BTComponent = nullptr;
};
