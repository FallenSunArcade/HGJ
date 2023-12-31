// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Blueprint/UserWidget.h"
#include "HG_ListEntry.generated.h"

class UHG_DialogObject;
class UButton;
class UTextBlock;

UCLASS()
class HGJ13_API UHG_ListEntry : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;

	UFUNCTION()
	void OnButtonClicked();

	UFUNCTION()
	void OnButtonHovered();

	UFUNCTION()
	void OnButtonUnHovered();
	
private:
	UPROPERTY(meta = (BindWidget))
	UButton* DialogButton;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* DialogText;
	
	UPROPERTY()
	UHG_DialogObject * DialogObject = nullptr;
};
