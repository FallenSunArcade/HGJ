// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HG_InteractionSphere.generated.h"


class UStaticMeshComponent;

UCLASS()
class HGJ13_API AHG_InteractionSphere : public AActor
{
	GENERATED_BODY()

public:
	AHG_InteractionSphere();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComponent;
	
protected:
	virtual void BeginPlay() override;


};
