// Fill out your copyright notice in the Description page of Project Settings.


#include "GameBooth/HG_GameBoothBase.h"
#include "Components/HG_DialogComponent.h"
#include "Components/WidgetComponent.h"


AHG_GameBoothBase::AHG_GameBoothBase()
{
	PrimaryActorTick.bCanEverTick = false;

	DialogComponent = CreateDefaultSubobject<UHG_DialogComponent>(TEXT("Dialog Component"));

	DialogComponent->GetInteractionWidget()->SetupAttachment(RootComponent);

	DialogComponent->SetOwningActor(this);
}

void AHG_GameBoothBase::BeginPlay()
{
	Super::BeginPlay();

	RoundStartDelegate.AddDynamic(this, &AHG_GameBoothBase::RoundStart);
	RoundOverDelegate.AddDynamic(this, &AHG_GameBoothBase::RoundOver);
}

