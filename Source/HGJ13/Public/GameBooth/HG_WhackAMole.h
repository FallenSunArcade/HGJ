// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HG_GameBoothBase.h"
#include "HG_WhackAMole.generated.h"


UCLASS()
class HGJ13_API AHG_WhackAMole : public AHG_GameBoothBase
{
	GENERATED_BODY()

public:
	AHG_WhackAMole();

	void TargetHit(bool Head);

	void StartRound();

	UFUNCTION()
	void RoundTick();
	
protected:
	virtual void BeginPlay() override;

	FTimerHandle RoundTimerHandle;
	
	UPROPERTY(EditAnywhere)
	int32 MaxRoundTime = 30;
	
	int32 RoundTime = 0;

	int32 NumTargets = 0;

	int32 CurrentScore = 0;
};
