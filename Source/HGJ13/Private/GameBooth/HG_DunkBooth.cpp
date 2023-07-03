// Fill out your copyright notice in the Description page of Project Settings.


#include "GameBooth/HG_DunkBooth.h"
#include "Components/HG_DialogComponent.h"
#include "Components/WidgetComponent.h"
#include "GameModes/HG_CarnivalGameMode.h"
#include "Kismet/GameplayStatics.h"

AHG_DunkBooth::AHG_DunkBooth()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	DialogComponent = CreateDefaultSubobject<UHG_DialogComponent>(TEXT("Dialog"));
	DialogComponent->GetInteractionWidget()->SetupAttachment(RootComponent);
}

void AHG_DunkBooth::BeginPlay()
{
	Super::BeginPlay();

	AHG_CarnivalGameMode* GameMode = Cast<AHG_CarnivalGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	check(GameMode);
	GameMode->SetDunkBooth(this);
}

