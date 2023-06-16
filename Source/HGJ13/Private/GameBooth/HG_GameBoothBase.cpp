// Fill out your copyright notice in the Description page of Project Settings.


#include "GameBooth/HG_GameBoothBase.h"
#include "Components/StateTreeComponent.h"


AHG_GameBoothBase::AHG_GameBoothBase()
{
	PrimaryActorTick.bCanEverTick = false;

	StateTree = CreateDefaultSubobject<UStateTreeComponent>(TEXT("State Tree"));
}
