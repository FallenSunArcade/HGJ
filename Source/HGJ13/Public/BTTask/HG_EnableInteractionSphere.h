// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "HG_EnableInteractionSphere.generated.h"

enum class EInteractionSphere : uint8;

UCLASS()
class HGJ13_API UHG_EnableInteractionSphere : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	UPROPERTY(EditAnywhere, Category = "Interaction Sphere")
	EInteractionSphere EInteractionSphere;
};
