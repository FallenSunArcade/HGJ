// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask/HG_Speak.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "UI/HG_HudOverlay.h"


EBTNodeResult::Type UHG_Speak::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	BTComponent = &OwnerComp;
	const UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();

	check(BlackboardComponent);
	
    HudOverlay = Cast<UHG_HudOverlay>(BlackboardComponent->GetValueAsObject("Hud"));
	
	if(HudOverlay)
	{
		HudOverlay->OverlayClickedDelegate.AddDynamic(this, &UHG_Speak::HudWasClicked);
	}
	else
	{
		return EBTNodeResult::Failed;
	}
	
	return EBTNodeResult::InProgress;
}

void UHG_Speak::HudWasClicked()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red,
	FString::Printf(TEXT("Hud overlay clicked task complete. (%s)"), *Dialog.ToString()));

	HudOverlay->OverlayClickedDelegate.RemoveAll(this);
	
	FinishLatentTask(*BTComponent, EBTNodeResult::Succeeded);
}
