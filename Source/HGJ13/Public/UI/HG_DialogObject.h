// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HG_DialogObject.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FReplySelectedDelegate, int32, ReplyIndex, bool, IsHostile);

USTRUCT(BlueprintType)
struct FPlayerReply
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	bool IsHostile = false;
	
	UPROPERTY(EditAnywhere)
	FText Reply;
	
	UPROPERTY(EditAnywhere)
	int32 Index;
};

UCLASS()
class HGJ13_API UHG_DialogObject : public UObject
{
	GENERATED_BODY()

public:
	FPlayerReply PlayerReply;

	UPROPERTY(BlueprintAssignable)
	FReplySelectedDelegate ReplySelectedDelegate;
};                       
