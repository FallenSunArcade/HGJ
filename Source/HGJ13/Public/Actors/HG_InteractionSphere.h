// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HG_InteractionSphere.generated.h"

UENUM(BlueprintType)
enum class EInteractionSphere : uint8 {
	SphereMole,
	SphereDunk
};

class UHG_DialogComponent;
class USphereComponent;

UCLASS()
class HGJ13_API AHG_InteractionSphere : public AActor
{
	GENERATED_BODY()

public:
	AHG_InteractionSphere();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	UHG_DialogComponent* DialogComponent;
	
	UPROPERTY(EditAnywhere)
	USphereComponent* SphereComponent;
	
	UPROPERTY(EditAnywhere)
	EInteractionSphere InteractionSphere = EInteractionSphere::SphereMole;

	UFUNCTION()
	void OverlapBegin(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult & SweepResult);

	UFUNCTION()
	void OverlapEnd(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);
};
