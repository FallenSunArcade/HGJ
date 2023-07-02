// Fill out your copyright notice in the Description page of Project Settings.


#include "GameBooth/HG_MoleTarget.h"

#include "GameBooth/HG_WhackAMole.h"
#include "GameModes/HG_CarnivalGameMode.h"
#include "Kismet/GameplayStatics.h"


AHG_MoleTarget::AHG_MoleTarget()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AHG_MoleTarget::BeginPlay()
{
	Super::BeginPlay();
	
}

float AHG_MoleTarget::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	if(const AHG_CarnivalGameMode* GameMode = Cast<AHG_CarnivalGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
	{
		AHG_WhackAMole* WhackAMole = GameMode->GetWhackAMole();
		check(WhackAMole);
		WhackAMole->TargetHit(bIsHead);
	}
	return Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
}


