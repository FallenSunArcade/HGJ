// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/HG_InteractionSphere.h"


AHG_InteractionSphere::AHG_InteractionSphere()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("Root Component");

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Collision Shape");
	MeshComponent->SetupAttachment(RootComponent);
	
}

void AHG_InteractionSphere::BeginPlay()
{
	Super::BeginPlay();
	
}

