// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HG_GameAlerts.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAlertDelegate);

class UTextBlock;

UCLASS()
class HGJ13_API UHG_GameAlerts : public UUserWidget
{
	GENERATED_BODY()

public:
	void DisplayAlert(const FText& Alert, float Duration = 3.f);

	UPROPERTY(BlueprintAssignable)
	FAlertDelegate AlertDelegate;

	UFUNCTION(BlueprintImplementableEvent)
	void GameAlert();

protected:
	virtual void NativeOnInitialized() override;
	
private:
	void RemoveAlert();
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* AlertMessage;

	FTimerHandle AlertTimerHandle;
};
