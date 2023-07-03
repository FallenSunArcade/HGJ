// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HG_DunkBooth.generated.h"

class UHG_DialogComponent;

UCLASS()
class HGJ13_API AHG_DunkBooth : public AActor
{
	GENERATED_BODY()

public:
	AHG_DunkBooth();

	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	UHG_DialogComponent* DialogComponent;
};
