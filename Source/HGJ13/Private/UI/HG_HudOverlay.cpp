// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HG_HudOverlay.h"

void UHG_HudOverlay::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	
}

FReply UHG_HudOverlay::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	FReply Reply = Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);

	if(InMouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red,
	FString::Printf(TEXT("Hud overlay clicked")));
	}

	
	return Reply;
}
