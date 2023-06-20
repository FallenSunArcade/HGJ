// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/HG_DialogComponent.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ToolBox/HG_LogCategories.h"
#include "Components/WidgetComponent.h"
#include "UI/HG_HudOverlay.h"
#include "Controllers/HG_PlayerController.h"


UHG_DialogComponent::UHG_DialogComponent()
{
	PrimaryComponentTick.bCanEverTick = false; 
	
	InteractionWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Interaction Widget"));

	//InteractionWidget->GetWidget()->SetVisibility(ESlateVisibility::Hidden);
}

void UHG_DialogComponent::OnInteraction_Implementation(AHG_PlayerController* PlayerController)
{
	IHG_Interactable::OnInteraction_Implementation(PlayerController);
	UE_LOG(LogInteraction, Display, TEXT("OnInteraction_Implementation (%s)"), *GetName());

	if(PlayerController)
	{
		const FInputModeUIOnly InputModeUIOnly;
		PlayerController->SetInputMode(InputModeUIOnly);
		PlayerController->SetShowMouseCursor(true);
		PlayerControllerRef = PlayerController;

		if(UBlackboardComponent* BlackboardComponent = AIController->GetBlackboardComponent())
		{
			BlackboardComponent->SetValueAsObject("Hud", PlayerControllerRef->GetHudOverlay());
		}
	}

}

void UHG_DialogComponent::BeginPlay()
{
	Super::BeginPlay();
	AIController = GetWorld()->SpawnActor<AAIController>(AAIController::StaticClass());

	check(AIController);
	
	if(DialogTree)
	{
		AIController->RunBehaviorTree(DialogTree);
	}
}
