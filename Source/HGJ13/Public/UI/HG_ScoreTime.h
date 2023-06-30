// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HG_ScoreTime.generated.h"

class UTextBlock;

UCLASS()
class HGJ13_API UHG_ScoreTime : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;

	void SetScore(int32 NewScore);

	void SetTime(int32 NewTime);
	
private:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* Time;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Score;
};
