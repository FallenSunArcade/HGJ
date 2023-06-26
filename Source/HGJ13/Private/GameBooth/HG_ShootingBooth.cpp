// Fill out your copyright notice in the Description page of Project Settings.


#include "GameBooth/HG_ShootingBooth.h"
#include "Components/SplineComponent.h"
#include "GameBooth/HG_DuckTarget.h"



AHG_ShootingBooth::AHG_ShootingBooth()
{
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

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
	
	switch (CurrentRound)
	{
	case ERounds::Round1:
		{
			RoundStartDelegate.Broadcast(1);
			break;
		}
	case ERounds::Round2:
		{
			RoundStartDelegate.Broadcast(2);
			break;
		}
	case ERounds::Round3:
		{
			RoundStartDelegate.Broadcast(3);
			break;
		}
	default:
		break;
		
	}
}

void AHG_ShootingBooth::BeginPlay()
{
	Super::BeginPlay();
	
	AHG_DuckTarget* Duck1 = GetWorld()->SpawnActor<AHG_DuckTarget>(DuckTargetClass,
		SplineComponent->GetComponentTransform());

	AHG_DuckTarget* Duck2 = GetWorld()->SpawnActor<AHG_DuckTarget>(DuckTargetClass,
	SplineComponent->GetComponentTransform());
	
	if(Duck1)
	{
		Duck1->MoveDuckOnSpline(SplineComponent, .1f, 9.f);
	}

	if(Duck2)
	{
		Duck2->MoveDuckOnSpline(SplineComponent, .2f, 9.f);
	}
}

