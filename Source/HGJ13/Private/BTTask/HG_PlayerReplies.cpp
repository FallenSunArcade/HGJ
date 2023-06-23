// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask/HG_PlayerReplies.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UI/HG_HudOverlay.h"
#include "UI/HG_Dialog.h"


EBTNodeResult::Type UHG_PlayerReplies::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	BTComponent = &OwnerComp;
	const UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	
	check(BlackboardComponent);
	
	HudOverlay = Cast<UHG_HudOverlay>(BlackboardComponent->GetValueAsObject("Hud"));
	
	if(HudOverlay)
	{
		for(int i = 0; i < Replies.Num(); ++i)
		{
			UHG_DialogObject* DialogObject = NewObject<UHG_DialogObject>();
			DialogObject->PlayerReply = Replies[i];
			DialogObject->ReplySelectedDelegate.AddDynamic(this, &UHG_PlayerReplies::ReplyWasSelected);
			RepliesObjects.Emplace(DialogObject);
		}
		
		UHG_Dialog* DialogWidget = HudOverlay->GetDialogWidget();
		check(DialogWidget);
		DialogWidget->SetReplies(RepliesObjects);
		DialogWidget->SetWidgetIndex(1);
		DialogWidget->SetActiveWidgetVisibility(true);
	}
	else
	{
		return EBTNodeResult::Failed;
	}
	
	return EBTNodeResult::InProgress;
}

void UHG_PlayerReplies::ReplyWasSelected(int32 Index, bool IsHostile)
{
	for(int i = 0; i < RepliesObjects.Num(); ++i)
	{
		RepliesObjects[i]->ReplySelectedDelegate.RemoveAll(this);
	}
	RepliesObjects.Empty();

	UHG_Dialog* DialogWidget = HudOverlay->GetDialogWidget();
	check(DialogWidget);
	DialogWidget->SetActiveWidgetVisibility(false);
	FinishLatentTask(*BTComponent, EBTNodeResult::Succeeded);
}
