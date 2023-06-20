// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "HG_PlayerController.generated.h"


class UHG_HudOverlay;

UCLASS()
class HGJ13_API AHG_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AHG_PlayerController();

	UHG_HudOverlay* GetHudOverlay() const {return HudOverlay;}
 
protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;
	
	virtual void Tick(float DeltaTime) override;

	void Interact();

private:
	UPROPERTY(EditAnywhere, Category = "HUD")
	TSubclassOf<UUserWidget> HudWidgetClass;

	UPROPERTY()
	UHG_HudOverlay* HudOverlay;
};
