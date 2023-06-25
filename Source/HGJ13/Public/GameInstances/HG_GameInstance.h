// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "HG_GameInstance.generated.h"

UENUM(BlueprintType)
enum class ECarnival : uint8 {
	ShootingBooth,
	WhackAMole,
	DunkTank,
	FerrisWheel
};

UCLASS()
class HGJ13_API UHG_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	ECarnival GetCurrentCarnivalBooth() const {return CurrentBooth;}
	
    void SetCarnivalBooth(ECarnival CarnivalState);
	
private:
	ECarnival CurrentBooth = ECarnival::ShootingBooth;
};
