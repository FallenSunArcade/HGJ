// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "HG_Speak.generated.h"

class UHG_HudOverlay;

UCLASS()
class HGJ13_API UHG_Speak : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UFUNCTION()
	void HudWasClicked();
	
private:
	UPROPERTY(EditAnywhere, Category = "Dialog")
	FText Dialog;

	UPROPERTY()
	UBehaviorTreeComponent* BTComponent = nullptr;

	UPROPERTY()
	UHG_HudOverlay* HudOverlay = nullptr;
};
