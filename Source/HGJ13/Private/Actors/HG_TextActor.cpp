// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/HG_TextActor.h"
#include "Components/HG_GameTipComponent.h"


AHG_TextActor::AHG_TextActor()
{
	PrimaryActorTick.bCanEverTick = false;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	TextWidget = CreateDefaultSubobject<UHG_GameTipComponent>(TEXT("Text Widget"));
	TextWidget->SetupAttachment(RootComponent);
}

void AHG_TextActor::BeginPlay()
{
	Super::BeginPlay();
	TextWidget->SetGameTipText(GameTip);
}

