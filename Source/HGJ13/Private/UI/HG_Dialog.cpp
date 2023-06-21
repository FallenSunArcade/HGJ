// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HG_Dialog.h"

#include "Components/TextBlock.h"
#include "Components/WidgetSwitcher.h"

void UHG_Dialog::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UHG_Dialog::SetWidgetIndex(int32 Index)
{
	check(DialogSwitcher);
	DialogSwitcher->SetActiveWidgetIndex(Index);
}

void UHG_Dialog::SetActiveWidgetVisibility(bool IsVisible)
{
	UWidget* ActiveWidget = DialogSwitcher->GetActiveWidget();

	if(IsVisible)
	{
		ActiveWidget->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		ActiveWidget->SetVisibility(ESlateVisibility::Hidden);
	}
}

void UHG_Dialog::SetSpeakText(const FText& Text)
{
	check(NPCText);
	NPCText->SetText(Text);
}
