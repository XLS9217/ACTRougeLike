// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SAction_Effect.h"
#include "SActionEffect_Thorns.generated.h"

/**
 * 
 */
UCLASS()
class ACTROUGELIKE_API USActionEffect_Thorns : public USAction_Effect
{
	GENERATED_BODY()
protected:

	UPROPERTY(EditDefaultsOnly, Category = "Thorns")
	float ReflectFraction;

	UFUNCTION()
	void OnHealthChanged(AActor* InstigatorActor, USAttributeComponent* OwningComp, float NewHealth, float Delta);

public:

	void StartAction_Implementation(AActor* Instigator) override;

	void StopAction_Implementation(AActor* Instigator) override;

	USActionEffect_Thorns();
};
