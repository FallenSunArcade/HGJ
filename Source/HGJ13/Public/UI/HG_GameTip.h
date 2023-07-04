// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HG_GameTip.generated.h"

class UTextBlock;

UCLASS()
class HGJ13_API UHG_GameTip : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;

	void SetGameTipText(const FText& Text);
	
private:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* GameTip;
};
