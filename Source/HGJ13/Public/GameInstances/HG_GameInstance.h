// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "HG_GameInstance.generated.h"

UENUM(BlueprintType)
enum class EGameStates : uint8 {
	ShootingBooth,
	DreamWorld1,
	WhackAMole,
	DreamWorld2,
	DunkTank,
	DreamWorld3,
	FerrisWheel,
	DreamWorld4
};

UENUM(BlueprintType)
enum class EDialogSections : uint8 {
	Section1,
	Section2,
	Section3,
	Section4,
	Section5,
	Section6,
	Section7,
	Section8,
	Section9
};


UCLASS()
class HGJ13_API UHG_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	EGameStates GetGameState() const {return CurrentState;}

	UFUNCTION(BlueprintCallable)
    void SetGameState(EGameStates NewState) {CurrentState = NewState;}

	UFUNCTION(BlueprintCallable)
	EDialogSections GetCurrentDialogSection() const {return CurrentDialogSection;}

	UFUNCTION(BlueprintCallable)
	void SetCurrentDialogSection(EDialogSections DialogSection) {CurrentDialogSection = DialogSection;}

	
private:
	UPROPERTY(EditAnywhere, Category = "Game")
	EGameStates CurrentState = EGameStates::ShootingBooth;

	UPROPERTY(EditAnywhere, Category = "Game")
	EDialogSections CurrentDialogSection = EDialogSections::Section1;
};
