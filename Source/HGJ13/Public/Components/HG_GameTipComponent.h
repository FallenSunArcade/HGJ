// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "HG_GameTipComponent.generated.h"

class UHG_GameTip;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class HGJ13_API UHG_GameTipComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:
	UHG_GameTipComponent();

	void SetGameTipText(const FText& Text);
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	UHG_GameTip* GameTip = nullptr;
};
