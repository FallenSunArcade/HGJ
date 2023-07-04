// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HG_TextActor.generated.h"

class UHG_GameTipComponent;

UCLASS()
class HGJ13_API AHG_TextActor : public AActor
{
	GENERATED_BODY()

public:
	AHG_TextActor();

	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Widget Component")
	UHG_GameTipComponent* TextWidget;

	UPROPERTY(EditAnywhere, Category = "Game Tip")
	FText GameTip;
};
