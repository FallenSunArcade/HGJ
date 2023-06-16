// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HG_Interactable.generated.h"


UINTERFACE(MinimalAPI)
class UHG_Interactable : public UInterface
{
	GENERATED_BODY()
};


class HGJ13_API IHG_Interactable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	void OnInteraction();
};
