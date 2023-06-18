// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HG_DialogObject.generated.h"


UCLASS()
class HGJ13_API UHG_DialogObject : public UObject
{
	GENERATED_BODY()

public:
	FText DialogText;
	bool bIsHostile = false;
};                       
