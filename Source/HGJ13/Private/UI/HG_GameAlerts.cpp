// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HG_GameAlerts.h"

#include "Components/TextBlock.h"

void UHG_GameAlerts::DisplayAlert(const FText& Alert, float Duration)
{
	AlertDelegate.Broadcast();
	AlertMessage->SetText(Alert);
	SetVisibility(ESlateVisibility::Visible);
	GetWorld()->GetTimerManager().SetTimer(AlertTimerHandle, this, &UHG_GameAlerts::RemoveAlert, Duration);
}

void UHG_GameAlerts::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	SetVisibility(ESlateVisibility::Hidden);
	AlertDelegate.AddDynamic(this, &UHG_GameAlerts::GameAlert);
}

void UHG_GameAlerts::RemoveAlert()
{
	SetVisibility(ESlateVisibility::Hidden);
}
