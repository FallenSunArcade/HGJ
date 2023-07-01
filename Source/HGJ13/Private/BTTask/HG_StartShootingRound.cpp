// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask/HG_StartShootingRound.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameBooth/HG_ShootingBooth.h"
#include "GameModes/HG_CarnivalGameMode.h"
#include "Kismet/GameplayStatics.h"

EBTNodeResult::Type UHG_StartShootingRound::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	check(BlackboardComponent);

	BTComponent = &OwnerComp;
	
	if(const AHG_CarnivalGameMode* GameMode = Cast<AHG_CarnivalGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
	{
		AHG_ShootingBooth* ShootingBooth = GameMode->GetShootingBooth();

		check(ShootingBooth);

		ShootingBooth->RoundOverDelegate.AddDynamic(this,  &UHG_StartShootingRound::RoundOver);
		ShootingBooth->StartRound();
	}
	
	return EBTNodeResult::InProgress;
}

void UHG_StartShootingRound::RoundOver()
{
	if(const AHG_CarnivalGameMode* GameMode = Cast<AHG_CarnivalGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
	{
		AHG_ShootingBooth* ShootingBooth = GameMode->GetShootingBooth();
		check(ShootingBooth);
		ShootingBooth->RoundOverDelegate.RemoveAll(this);
		FinishLatentTask(*BTComponent, EBTNodeResult::Succeeded);
	}
}
