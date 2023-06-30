// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "HG_EnableInteraction.generated.h"

UENUM(BlueprintType)
enum class EInteractable : uint8 {
	ShootingBooth,
	WhackAMole,
	WoMShootingBooth,
	WoMWackAMole,
	DunkBooth,
	FerrisWheel
};

UCLASS()
class HGJ13_API UHG_EnableInteraction : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	UPROPERTY(EditAnywhere, Category = "Interactable")
	EInteractable Interactable;
};
