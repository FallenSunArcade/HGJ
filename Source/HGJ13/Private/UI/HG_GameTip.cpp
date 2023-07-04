// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HG_GameTip.h"

#include "Components/TextBlock.h"

void UHG_GameTip::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UHG_GameTip::SetGameTipText(const FText& Text)
{
	GameTip->SetText(Text);
}
