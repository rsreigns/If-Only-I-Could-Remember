// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseAIController.generated.h"

UENUM(BlueprintType)
enum class EAIRole : uint8
{
	Civilian, Family, Ally, Enemy
};

UCLASS()
class FAMILYTRIP_API ABaseAIController : public AAIController
{
	GENERATED_BODY()

protected:
	ABaseAIController(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI|Crowd")
	bool bEnableCrowdSimulation = true;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI|Crowd")
	bool bEnableDetourCrowdAvoidance = true;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI|Crowd", 
	meta = (EditCondition = "bEnableDetourCrowdAvoidance" , UIMin = "1", UIMax = "4"))
	int32 DetourCrowdAvoidanceQuality = 4;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI|Crowd",
	meta = (EditCondition = "bEnableDetourCrowdAvoidance"))
	float CollisionQueryRange = 600.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI|Default")
	EAIRole AIRole = EAIRole::Enemy;

	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable, Category = "AI|Crowd")
	void HandleCrowdSimulation ( const bool EnableSimulation, const int32 AvoidanceQuality, const int32 AvoidanceGroup);

	
	
};
