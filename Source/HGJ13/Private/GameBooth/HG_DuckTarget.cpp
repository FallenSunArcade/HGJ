// Fill out your copyright notice in the Description page of Project Settings.


#include "GameBooth/HG_DuckTarget.h"

#include "Components/CapsuleComponent.h"
#include "Components/SplineComponent.h"

#define DEBUG false

AHG_DuckTarget::AHG_DuckTarget()
{
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision"));
	SetRootComponent(Collision);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	StaticMesh->SetupAttachment(Collision);
}

void AHG_DuckTarget::MoveDuckOnSpline(USplineComponent* Spline, float SplinePosition, float LoopTime)
{
	SplineRef = Spline;
	FOnTimelineFloat TimelineFloat;
	TimelineFloat.BindUFunction(this, TEXT("ProcessMovementTimeline"));
	Timeline.AddInterpFloat(CurveFloat, TimelineFloat);

	Timeline.SetPlayRate(1.f/LoopTime);
	Timeline.SetNewTime(SplinePosition);
	Timeline.SetLooping(true);
	Timeline.Play();
}

void AHG_DuckTarget::ProcessMovementTimeline(float Value)
{
	if(SplineRef)
	{
		const float SplineLength = SplineRef->GetSplineLength();

		const float Pos = FMath::Lerp(0.f, SplineLength, Value);
		const FTransform Transform = SplineRef->GetTransformAtDistanceAlongSpline(Pos, ESplineCoordinateSpace::World);
		SetActorTransform(Transform);
		
#if DEBUG
		GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Red,
			FString::Printf(TEXT("Value = %f, Lerp Pos = %f, SplineLength = %f"), Value, Pos, SplineLength));
#endif
	}

}

void AHG_DuckTarget::BeginPlay()
{
	
	Super::BeginPlay();

	
}

void AHG_DuckTarget::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if(Timeline.IsPlaying())
	{
		Timeline.TickTimeline(DeltaSeconds);
	}
}

void AHG_DuckTarget::Destroyed()
{
	Super::Destroyed();

	DuckDestroyedDelegate.Broadcast();
}

