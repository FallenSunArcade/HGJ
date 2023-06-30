// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HG_ScoreTime.h"
#include "Components/TextBlock.h"

void UHG_ScoreTime::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UHG_ScoreTime::SetScore(int32 NewScore)
{
	Score->SetText(FText::AsNumber(NewScore));
}

void UHG_ScoreTime::SetTime(int32 NewTime)
{
	Time->SetText(FText::AsNumber(NewTime));
}
