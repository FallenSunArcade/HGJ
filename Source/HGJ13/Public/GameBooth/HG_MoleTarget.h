// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HG_MoleTarget.generated.h"


UCLASS()
class HGJ13_API AHG_MoleTarget : public AActor
{
	GENERATED_BODY()

public:
	AHG_MoleTarget();
	
protected:
	virtual void BeginPlay() override;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsHead = false;
};
