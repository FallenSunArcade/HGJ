// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HG_HudOverlay.h"
#include "Components/Image.h"


void UHG_HudOverlay::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

FReply UHG_HudOverlay::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	FReply Reply = Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);

	if(InMouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
	{
		OverlayClickedDelegate.Broadcast();
	}

	
	return Reply;
}

void UHG_HudOverlay::StartGameTransition(float Delay, bool WithFadeIn)
{
	Opacity = 1.f;
	Transition->SetOpacity(1.f);
	GetWorld()->GetTimerManager().SetTimer(GameTransitionHandle, this, &UHG_HudOverlay::Transitioning, .1f, true, Delay);
}

void UHG_HudOverlay::Transitioning()
{
	Opacity -= .05f;
	if(Opacity > 0.f)
	{
		Transition->SetOpacity(Opacity);
	}
	else
	{
		Transition->SetOpacity(0.f);
		GetWorld()->GetTimerManager().ClearTimer(GameTransitionHandle);
		UE_LOG(LogTemp, Display, TEXT("Transition done (%s)"), *GetName());
	}
	
}
