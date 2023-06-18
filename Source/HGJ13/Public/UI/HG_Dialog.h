// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HG_Dialog.generated.h"

class UWidgetSwitcher;
class UTextBlock;
class UListView;

UCLASS()
class HGJ13_API UHG_Dialog : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;

private:
	UPROPERTY(meta = (BindWidget))
	UWidgetSwitcher* DialogSwitcher;
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* NPCText;

	UPROPERTY(meta = (BindWidget))
	UListView* PlayerRepliesList;
};
