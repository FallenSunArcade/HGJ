// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HG_GameBoard.h"
#include "UI/HG_ScoreTime.h"

UHG_GameBoard::UHG_GameBoard()
{

	PrimaryComponentTick.bCanEverTick = true;
}

void UHG_GameBoard::SetScore(int32 Score)
{
	ScoreBoardWidget->SetScore(Score);
}

void UHG_GameBoard::SetTime(int32 Time)
{
	ScoreBoardWidget->SetTime(Time);
}

void UHG_GameBoard::BeginPlay()
{
	Super::BeginPlay();

	ScoreBoardWidget = Cast<UHG_ScoreTime>(GetUserWidgetObject());
	check(ScoreBoardWidget);
}

