// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HG_GameTipComponent.h"
#include "UI/HG_GameTip.h"


UHG_GameTipComponent::UHG_GameTipComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UHG_GameTipComponent::SetGameTipText(const FText& Text)
{
	GameTip->SetGameTipText(Text);
}

void UHG_GameTipComponent::BeginPlay()
{
	Super::BeginPlay();

	GameTip = Cast<UHG_GameTip>(GetUserWidgetObject());
	check(GameTip);
}


