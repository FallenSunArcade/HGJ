// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "UI/HG_DialogObject.h"
#include "HG_PlayerReplies.generated.h"


class UHG_HudOverlay;

UCLASS()
class HGJ13_API UHG_PlayerReplies : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UFUNCTION()
	void ReplyWasSelected(float Duration, bool IsHostile, float Index);

	UFUNCTION()
	void ReplyDone();
	
private:
	UPROPERTY(EditAnywhere, Category = "Replies")
	TArray<FPlayerReply> Replies;
 
	UPROPERTY()
	UBehaviorTreeComponent* BTComponent = nullptr;

	UPROPERTY()
	UHG_HudOverlay* HudOverlay = nullptr;

	UPROPERTY()
	TArray<UHG_DialogObject*> RepliesObjects;

	FTimerHandle ReplyHandle;
};
