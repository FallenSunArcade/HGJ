// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask/HG_Speak.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UI/HG_HudOverlay.h"
#include "UI/HG_Dialog.h"


EBTNodeResult::Type UHG_Speak::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	BTComponent = &OwnerComp;
	const UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	
	check(BlackboardComponent);
	
    HudOverlay = Cast<UHG_HudOverlay>(BlackboardComponent->GetValueAsObject("Hud"));
	
	if(HudOverlay)
	{
		HudOverlay->OverlayClickedDelegate.AddDynamic(this, &UHG_Speak::HudWasClicked);
		UHG_Dialog* DialogWidget = HudOverlay->GetDialogWidget();
		DialogWidget->SetWidgetIndex(0);
		DialogWidget->SetActiveWidgetVisibility(true);
		DialogWidget->SetSpeakText(Dialog);
	}
	else
	{
		return EBTNodeResult::Failed;
	}
	
	return EBTNodeResult::InProgress;
}

void UHG_Speak::HudWasClicked()
{
	HudOverlay->OverlayClickedDelegate.RemoveAll(this);
	UHG_Dialog* DialogWidget = HudOverlay->GetDialogWidget();
	DialogWidget->SetActiveWidgetVisibility(false);
	FinishLatentTask(*BTComponent, EBTNodeResult::Succeeded);
}
