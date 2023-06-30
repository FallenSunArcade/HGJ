// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HG_WoM.generated.h"

UENUM(BlueprintType)
enum class EWom : uint8 {
	ShootingBooth,
	WhackAMole
};

class UHG_DialogComponent;

UCLASS()
class HGJ13_API AHG_WoM : public AActor
{
	GENERATED_BODY()

public:
	AHG_WoM();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	UHG_DialogComponent* DialogComponent;

	UPROPERTY(EditAnywhere)
	EWom Booth = EWom::ShootingBooth;
};
