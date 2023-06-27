// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HG_GameBoothBase.h"
#include "HG_WhackAMole.generated.h"

UCLASS()
class HGJ13_API AHG_WhackAMole : public AHG_GameBoothBase
{
	GENERATED_BODY()

public:
	AHG_WhackAMole();

protected:
	virtual void BeginPlay() override;
};
