// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/HG_BaseCharacter.h"

#include "Components/HG_DialogComponent.h"
#include "Components/WidgetComponent.h"


AHG_BaseCharacter::AHG_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	
	DialogComponent = CreateDefaultSubobject<UHG_DialogComponent>(TEXT("Dialog Component"));

	DialogComponent->GetInteractionWidget()->SetupAttachment(RootComponent);
}

void AHG_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


