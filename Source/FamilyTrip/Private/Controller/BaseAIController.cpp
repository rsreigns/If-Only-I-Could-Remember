// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/BaseAIController.h"

#include "Navigation/CrowdFollowingComponent.h"

ABaseAIController::ABaseAIController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>("PathFollowingComponent"))
{
	
}
void ABaseAIController::BeginPlay()
{
	Super::BeginPlay();

	
	HandleCrowdSimulation(bEnableCrowdSimulation,  DetourCrowdAvoidanceQuality, 1);
}

void ABaseAIController::HandleCrowdSimulation(const bool EnableSimulation,
	const int32 AvoidanceQuality, const int32 AvoidanceGroup)
{
	if ( UCrowdFollowingComponent* TempCrowdComp = Cast<UCrowdFollowingComponent>(GetPathFollowingComponent()); TempCrowdComp )
	{
		TempCrowdComp->SetCrowdSimulationState(EnableSimulation? ECrowdSimulationState::Enabled : ECrowdSimulationState::Disabled);

		switch (AvoidanceQuality)
		{
		case 1: 	TempCrowdComp->SetCrowdAvoidanceQuality(ECrowdAvoidanceQuality::Low);    break;
		case 2 :	TempCrowdComp->SetCrowdAvoidanceQuality(ECrowdAvoidanceQuality::Medium); break;
		case 3 :	TempCrowdComp->SetCrowdAvoidanceQuality(ECrowdAvoidanceQuality::Good);   break;
		case 4 : 	TempCrowdComp->SetCrowdAvoidanceQuality(ECrowdAvoidanceQuality::High);   break;
		default : 	TempCrowdComp->SetCrowdAvoidanceQuality(ECrowdAvoidanceQuality::High);   break;
		}

		TempCrowdComp->SetAvoidanceGroup(AvoidanceGroup);
		TempCrowdComp->SetGroupsToAvoid(1);
		TempCrowdComp->SetCrowdCollisionQueryRange(CollisionQueryRange);
	}
}
