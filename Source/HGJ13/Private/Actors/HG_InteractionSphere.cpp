// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/HG_InteractionSphere.h"
#include "Components/SphereComponent.h"
#include "GameModes/HG_CarnivalGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Components/HG_DialogComponent.h"
#include "Controllers/HG_PlayerController.h"


AHG_InteractionSphere::AHG_InteractionSphere()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("Root Component");

	SphereComponent = CreateDefaultSubobject<USphereComponent>("Collision Shape");
	SphereComponent->SetupAttachment(RootComponent);

	DialogComponent = CreateDefaultSubobject<UHG_DialogComponent>(TEXT("Dialog Component"));
}

void AHG_InteractionSphere::BeginPlay()
{
	Super::BeginPlay();

	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AHG_InteractionSphere::OverlapBegin);
	SphereComponent->OnComponentEndOverlap.AddDynamic(this, &AHG_InteractionSphere::OverlapEnd);
	
	if(AHG_CarnivalGameMode* GameMode = Cast<AHG_CarnivalGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
	{
		switch(InteractionSphere)
		{
		case EInteractionSphere::SphereMole:
			{
				GameMode->AddInteractionSphere(this, InteractionSphere);
				break;
			}
		default:
			break;
		}
	}
}

void AHG_InteractionSphere::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if(Cast<ACharacter>(OtherActor) == UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))
	{
		AHG_PlayerController * PlayerController = Cast<AHG_PlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
		check(PlayerController);
		DialogComponent->OnInteraction_Implementation(PlayerController);
	}
}

void AHG_InteractionSphere::OverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

