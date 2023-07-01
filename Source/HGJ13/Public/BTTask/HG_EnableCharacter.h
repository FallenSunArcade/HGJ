// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "HG_EnableCharacter.generated.h"

UENUM(BlueprintType)
enum class EGameBooth: uint8 {
	ShootingBooth,
	WhackAMole,
	DunkBooth,
	FerrisWheel
};

UCLASS()
class HGJ13_API UHG_EnableCharacter : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	UPROPERTY(EditAnywhere, Category = "Game Booth")
	EGameBooth GameBooth = EGameBooth::ShootingBooth;

	UPROPERTY(EditAnywhere, Category = "Game Booth")
	FString CharacterName;
};
