// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HG_HudOverlay.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOverlayClickedDelegate);


class UHG_GameAlerts;
class UHG_Dialog;

UCLASS()
class HGJ13_API UHG_HudOverlay : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;

	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

	UHG_GameAlerts* GetGameAlertsWidget() const {return GameAlerts;}

	UHG_Dialog* GetDialogWidget() const {return Dialogs;}

	UPROPERTY(BlueprintAssignable)
	FOverlayClickedDelegate OverlayClickedDelegate;
	
private:
	UPROPERTY(meta = (BindWidget))
	UHG_GameAlerts* GameAlerts;

	UPROPERTY(meta = (BindWidget))
	UHG_Dialog* Dialogs;
};
