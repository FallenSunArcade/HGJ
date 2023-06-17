// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/HG_DialogComponent.h"
#include "AIController.h"
#include "ToolBox/HG_LogCategories.h"
#include "Components/WidgetComponent.h"


UHG_DialogComponent::UHG_DialogComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	
	InteractionWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Interaction Widget"));
}

void UHG_DialogComponent::OnInteraction_Implementation(APlayerController* PlayerController)
{
	IHG_Interactable::OnInteraction_Implementation(PlayerController);
	UE_LOG(LogInteraction, Display, TEXT("OnInteraction_Implementation (%s)"), *GetName());

	FInputModeUIOnly InputModeUIOnly;

	PlayerController->SetInputMode(InputModeUIOnly);
}

void UHG_DialogComponent::BeginPlay()
{
	Super::BeginPlay();
	AIController = GetWorld()->SpawnActor<AAIController>(AAIController::StaticClass());

	if(DialogTree && AIController)
	{
		AIController->RunBehaviorTree(DialogTree);
	}
}
