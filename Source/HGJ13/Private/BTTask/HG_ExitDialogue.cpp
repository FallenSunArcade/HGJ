// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask/HG_ExitDialogue.h"
#include "Components/HG_DialogComponent.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UHG_ExitDialogue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	check(BlackboardComponent);
	
	if(UHG_DialogComponent* DialogComponent = Cast<UHG_DialogComponent>(BlackboardComponent->GetValueAsObject("Owner")))
	{
		DialogComponent->EndInteraction();
	}
	
	return EBTNodeResult::Succeeded;
}
