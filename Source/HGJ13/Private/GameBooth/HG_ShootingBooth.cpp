// Fill out your copyright notice in the Description page of Project Settings.


#include "GameBooth/HG_ShootingBooth.h"
#include "Components/SplineComponent.h"
#include "GameBooth/HG_DuckTarget.h"
#include "GameModes/HG_CarnivalGameMode.h"
#include "Kismet/GameplayStatics.h"


AHG_ShootingBooth::AHG_ShootingBooth()
{
	PrimaryActorTick.bCanEverTick = false;

	Tent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tent"));
	Tent->SetupAttachment(RootComponent);

	WoodenFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Wooden Frame"));
	WoodenFrame->SetupAttachment(RootComponent);

	Track = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Track"));
	Track->SetupAttachment(RootComponent);

	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
	SplineComponent->SetupAttachment(Track);
}

void AHG_ShootingBooth::StartRound()
{
	RoundTime = 10;
	NumTargets = 10;
	
	switch (CurrentRound)
	{
	case ERounds::Round1:
		{
			CurrentRound = ERounds::Round2;
			GetWorldTimerManager().SetTimer(RoundTimerHandle, this, &AHG_ShootingBooth::RoundTick, 1.f, true, 0.f);
			RoundStartDelegate.Broadcast(1);
			SetupTargets(9.f, false);
			break;
		}
	case ERounds::Round2:
		{
			CurrentRound = ERounds::Round3;
			GetWorldTimerManager().SetTimer(RoundTimerHandle, this, &AHG_ShootingBooth::RoundTick, 1.f, true, 0.f);
			RoundStartDelegate.Broadcast(2);
			SetupTargets(6.f, false);
			break;
		}
	case ERounds::Round3:
		{
			GetWorldTimerManager().SetTimer(RoundTimerHandle, this, &AHG_ShootingBooth::RoundTick, 1.f, true, 0.f);
			RoundStartDelegate.Broadcast(3);
			SetupTargets(6.f, true);
			break;
		}
	default:
		break;
		
	}
}

void AHG_ShootingBooth::RoundTick()
{
	--RoundTime;

	if(RoundTime <= 0)
	{
		for(int i = 0; i < Targets.Num(); ++i)
		{
			if(Targets[i])
			{
				Targets[i]->DuckDestroyedDelegate.RemoveAll(this);
				Targets[i]->Destroy();
			}
		}
		Targets.Empty();
		GetWorldTimerManager().ClearTimer(RoundTimerHandle);
		RoundOverDelegate.Broadcast(false);
	}
}

void AHG_ShootingBooth::RemoveDuck()
{
	--NumTargets;

	if(NumTargets <= 0)
	{
		Targets.Empty();
		RoundOverDelegate.Broadcast(true);
	}
}

void AHG_ShootingBooth::SetupTargets(float LoopTime, bool AddHeads)
{
	for(int i = 0; i < NumTargets; ++i)
	{
		AHG_DuckTarget* Duck = GetWorld()->SpawnActor<AHG_DuckTarget>(DuckTargetClass,
	SplineComponent->GetComponentTransform());
		Duck->MoveDuckOnSpline(SplineComponent, (.1f + i*.1f), LoopTime);
		Duck->DuckDestroyedDelegate.AddDynamic(this, &AHG_ShootingBooth::RemoveDuck);
		Targets.Emplace(Duck);
	}
}

void AHG_ShootingBooth::BeginPlay()
{
	Super::BeginPlay();

	AHG_CarnivalGameMode* GameMode = Cast<AHG_CarnivalGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	check(GameMode);

	GameMode->SetShootingBooth(this);
}

