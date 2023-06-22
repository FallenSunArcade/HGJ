// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interfaces/HG_Interactable.h"
#include "HG_DialogComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSpeakingDelegate, int32, DialogueIndex, bool, IsHostile);

class AAIController;
class UHG_HudOverlay;
class UBehaviorTree;
class UWidgetComponent;
class AHG_PlayerController;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class HGJ13_API UHG_DialogComponent : public UActorComponent, public IHG_Interactable
{
	GENERATED_BODY()

public:
	UHG_DialogComponent();
	virtual void OnInteraction_Implementation(AHG_PlayerController* PlayerController) override;

	void EndInteraction();
	
	UWidgetComponent* GetInteractionWidget() const {return InteractionWidget;}

	bool CanSpeak() const {return bCanSpeak;}

	UPROPERTY(BlueprintAssignable)
	FSpeakingDelegate SpeakingDelegate;
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Interaction")
	UBehaviorTree* DialogTree;

	UPROPERTY(EditAnywhere, Category = "Interaction")
	UWidgetComponent* InteractionWidget;
	
	UPROPERTY()
	AAIController* AIController;

	UPROPERTY()
	AHG_PlayerController* PlayerControllerRef;

	bool bCanSpeak = false;
};

