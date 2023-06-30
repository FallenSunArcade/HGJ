// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "HG_GameBoard.generated.h"

class UHG_ScoreTime;


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class HGJ13_API UHG_GameBoard : public UWidgetComponent
{
	GENERATED_BODY()

public:
	UHG_GameBoard();

	void SetScore(int32 Score);

	void SetTime(int32 Time);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	UHG_ScoreTime* ScoreBoardWidget = nullptr;
};
