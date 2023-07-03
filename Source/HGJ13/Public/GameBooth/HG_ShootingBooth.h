// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HG_GameBoothBase.h"
#include "HG_ShootingBooth.generated.h"

class USplineComponent;
class AHG_DuckTarget;

UCLASS()
class HGJ13_API AHG_ShootingBooth : public AHG_GameBoothBase
{
	GENERATED_BODY()

public:
	AHG_ShootingBooth();

	UFUNCTION(BlueprintCallable)
	void StartRound();

	UFUNCTION()
	void RoundTick();

	UFUNCTION()
	void RemoveDuck(bool IsHead);

	void SetupTargets(float LoopTime, bool AddHeads);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tent", meta = (AllowPrivateAccess))
	UStaticMeshComponent* Tent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tent", meta = (AllowPrivateAccess))
	UStaticMeshComponent* WoodenFrame = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Track", meta = (AllowPrivateAccess))
	UStaticMeshComponent* Track = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Track", meta = (AllowPrivateAccess))
	USplineComponent* SplineComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Track", meta = (AllowPrivateAccess))
	TSubclassOf<AHG_DuckTarget> DuckTargetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Track", meta = (AllowPrivateAccess))
	TSubclassOf<AHG_DuckTarget> HeadTargetClass;

	UPROPERTY()
	TArray<AHG_DuckTarget*> Targets;
	
	FTimerHandle RoundTimerHandle;

	UPROPERTY(EditAnywhere)
	int32 MaxRoundTime = 15;
	
	int32 RoundTime = 0;

	int32 NumTargets = 0;

	int32 CurrentScore = 0;
};
