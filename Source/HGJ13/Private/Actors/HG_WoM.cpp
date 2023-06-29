// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/HG_WoM.h"
#include "Components/HG_DialogComponent.h"
#include "Components/WidgetComponent.h"
#include "GameModes/HG_CarnivalGameMode.h"
#include "Kismet/GameplayStatics.h"


AHG_WoM::AHG_WoM()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	DialogComponent = CreateDefaultSubobject<UHG_DialogComponent>(TEXT("Dialog Component"));
	DialogComponent->GetInteractionWidget()->SetupAttachment(RootComponent);
	DialogComponent->SetOwningActor(this);
}

void AHG_WoM::BeginPlay()
{
	Super::BeginPlay();

	AHG_CarnivalGameMode* GameMode = Cast<AHG_CarnivalGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	check(GameMode);

	GameMode->SetWom(this);
}


