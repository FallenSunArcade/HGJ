// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HG_BaseCharacter.generated.h"

class UHG_DialogComponent;

UCLASS()
class HGJ13_API AHG_BaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AHG_BaseCharacter();
	UHG_DialogComponent* GetDialogComponent() const {return DialogComponent;}

	UFUNCTION(BlueprintImplementableEvent)
	void Speaking(int32 DialogueIndex, bool IsHostile);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	UHG_DialogComponent* DialogComponent;
};
