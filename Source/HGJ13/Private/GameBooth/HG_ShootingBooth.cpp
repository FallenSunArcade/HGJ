// Fill out your copyright notice in the Description page of Project Settings.


#include "GameBooth/HG_ShootingBooth.h"
#include "Components/HG_GameBoard.h"
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
	ScoreBoard->SetScore(CurrentScore);
	ScoreBoard->SetTime(10);
	
	RoundTime = MaxRoundTime;
	NumTargets = 10;
	
	switch (CurrentRound)
	{
	case ERounds::Round1:
		{
			GetWorldTimerManager().SetTimer(RoundTimerHandle, this, &AHG_ShootingBooth::RoundTick, 1.f, true, 1.f);
			RoundStartDelegate.Broadcast(1);
			SetupTargets(9.f, false);
			break;
		}
	case ERounds::Round2:
		{
			GetWorldTimerManager().SetTimer(RoundTimerHandle, this, &AHG_ShootingBooth::RoundTick, 1.f, true, 1.f);
			RoundStartDelegate.Broadcast(2);
			SetupTargets(6.f, false);
			break;
		}
	case ERounds::Round3:
		{
			GetWorldTimerManager().SetTimer(RoundTimerHandle, this, &AHG_ShootingBooth::RoundTick, 1.f, true, 1.f);
			RoundStartDelegate.Broadcast(3);
			break;
		}
	default:
		break;
		
	}
}

void AHG_ShootingBooth::RoundTick()
{
	--RoundTime;
	
	ScoreBoard->SetTime(RoundTime);

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

		if(CurrentRound == ERounds::Round3)
		{
			if(CurrentScore > 17)
			{
				GameOverDelegate.Broadcast(true);
			}
			else
			{
				GameOverDelegate.Broadcast(false);
			}
		}
		if(CurrentRound == ERounds::Round1)
		{
			CurrentRound = ERounds::Round2;
		}
		else
		{
			ScoreBoard->SetTime(10);
			NumTargets = 10;
			CurrentRound = ERounds::Round3;
		}
		RoundOverDelegate.Broadcast();
	}
}

void AHG_ShootingBooth::RemoveDuck(bool IsHead)
{
	if(IsHead)
	{
		GameOverDelegate.Broadcast(false);
		RoundOverDelegate.Broadcast();
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
	}
	--NumTargets;
	++CurrentScore;
	ScoreBoard->SetScore(CurrentScore);
}

void AHG_ShootingBooth::SetupTargets(float LoopTime, bool AddHeads)
{
	for (int i = 0; i < NumTargets; ++i)
	{
		const bool Head = (i % 2 == 0);

		if (Head && AddHeads)
		{
			AHG_DuckTarget* Duck = GetWorld()->SpawnActor<AHG_DuckTarget>(HeadTargetClass,
			                                                              SplineComponent->GetComponentTransform());
			Duck->MoveDuckOnSpline(SplineComponent, (.1f + i * .1f), LoopTime);
			Duck->DuckDestroyedDelegate.AddDynamic(this, &AHG_ShootingBooth::RemoveDuck);
			Duck->SetIsHead(true);
			Targets.Emplace(Duck);
		}
		else
		{
			AHG_DuckTarget* Duck = GetWorld()->SpawnActor<AHG_DuckTarget>(DuckTargetClass,
			                                                              SplineComponent->GetComponentTransform());
			Duck->MoveDuckOnSpline(SplineComponent, (.1f + i * .1f), LoopTime);
			Duck->DuckDestroyedDelegate.AddDynamic(this, &AHG_ShootingBooth::RemoveDuck);
			Targets.Emplace(Duck);
		}
	}
}

void AHG_ShootingBooth::BeginPlay()
{
	Super::BeginPlay();

	AHG_CarnivalGameMode* GameMode = Cast<AHG_CarnivalGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	check(GameMode);
	GameMode->SetShootingBooth(this);

	ScoreBoard->SetScore(17);
}

