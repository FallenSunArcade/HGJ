// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask/HG_PlayerReplies.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BrainComponent.h"
#include "UI/HG_HudOverlay.h"
#include "UI/HG_Dialog.h"
#include "GameModes/HG_CarnivalGameMode.h"
#include "Kismet/GameplayStatics.h"


EBTNodeResult::Type UHG_PlayerReplies::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	BTComponent = &OwnerComp;
	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	
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

void UHG_PlayerReplies::ReplyWasSelected(FText ReplyText, bool IsHostile, float Index)
{
	UBlackboardComponent* BlackboardComponent = BTComponent->GetBlackboardComponent();

	UHG_Dialog* DialogWidget = HudOverlay->GetDialogWidget();
	DialogWidget->SetWidgetIndex(0);
	DialogWidget->SetActiveWidgetVisibility(true);
	DialogWidget->SetSpeakText(ReplyText);
	
	if(const AHG_CarnivalGameMode* GameMode = Cast<AHG_CarnivalGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
	{
		GameMode->SpeakingDelegate.Broadcast(Index);
	}
	
	if(IsHostile)
	{
		BlackboardComponent->SetValueAsString("ReplyType", "Hostile");
	}
	else
	{
		BlackboardComponent->SetValueAsString("ReplyType", "Friendly");
	}
	
	for(int i = 0; i < RepliesObjects.Num(); ++i)
	{
		RepliesObjects[i]->ReplySelectedDelegate.RemoveAll(this);
	}

	HudOverlay->OverlayClickedDelegate.AddDynamic(this, &UHG_PlayerReplies::ReplyDone);
}

void UHG_PlayerReplies::ReplyDone()
{
	HudOverlay->OverlayClickedDelegate.RemoveAll(this);
	RepliesObjects.Empty();
	UHG_Dialog* DialogWidget = HudOverlay->GetDialogWidget();
	check(DialogWidget);
	DialogWidget->SetActiveWidgetVisibility(false);

	if(const AHG_CarnivalGameMode* GameMode = Cast<AHG_CarnivalGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
	{
		GameMode->SpeakingDelegate.Broadcast(0);
	}
	
	FinishLatentTask(*BTComponent, EBTNodeResult::Succeeded);
}
