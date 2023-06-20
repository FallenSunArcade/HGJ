// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HG_GameBoothBase.generated.h"

class UStateTreeComponent;

UCLASS()
class HGJ13_API AHG_GameBoothBase : public AActor
{
	GENERATED_BODY()

public:
	AHG_GameBoothBase();

protected:
	UPROPERTY(EditAnywhere, Category = "Game Booth")
	UStateTreeComponent* StateTree = nullptr;

	UPROPERTY(EditAnywhere, Category = "Game Booth")
	bool bHasTickets = false;
};
