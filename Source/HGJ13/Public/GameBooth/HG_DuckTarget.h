// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TimelineComponent.h"
#include "GameFramework/Actor.h"
#include "HG_DuckTarget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDuckDestroyedDelegate, bool, TargetIsHead);

class UCapsuleComponent;
class UStaticMeshComponent;
class USplineComponent;
class UCurveFloat;

UCLASS()
class HGJ13_API AHG_DuckTarget : public AActor
{
	GENERATED_BODY()

public:
	AHG_DuckTarget();
	
	void MoveDuckOnSpline(USplineComponent* Spline, float SplinePosition, float LoopTime);

	UFUNCTION()
	void ProcessMovementTimeline(float Value);

	FDuckDestroyedDelegate DuckDestroyedDelegate;

	bool IsHead() const {return bIsHead;}

	void SetIsHead(bool Head) {bIsHead = Head;}
	
protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	virtual void Destroyed() override;

private:
	UPROPERTY(EditAnywhere, Category = "Components")
	UCapsuleComponent* Collision = nullptr;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* StaticMesh = nullptr;

	UPROPERTY(EditAnywhere, Category = "Movement")
	UCurveFloat* CurveFloat = nullptr;

	UPROPERTY()
	USplineComponent* SplineRef = nullptr;
	
	FTimeline Timeline;

	bool bIsHead = false;
};
