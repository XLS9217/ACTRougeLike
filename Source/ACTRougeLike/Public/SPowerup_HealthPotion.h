// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SPowerupActor.h"
#include "SPowerup_HealthPotion.generated.h"

/**
 * 
 */
UCLASS()
class ACTROUGELIKE_API ASPowerup_HealthPotion : public ASPowerupActor
{
	GENERATED_BODY()
protected:

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, Category = "HealthPotion")
	int32 CreditCost;

	// float healt amount?

public:

	void Interact_Implementation(APawn* InstigatorPawn) override;

	ASPowerup_HealthPotion();
};
