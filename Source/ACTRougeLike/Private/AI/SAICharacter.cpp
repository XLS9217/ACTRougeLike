// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/SAICharacter.h"
#include <Perception/PawnSensingComponent.h>
#include <AIController.h>
#include "BehaviorTree/BlackboardComponent.h"
#include "BrainComponent.h"

// Sets default values
ASAICharacter::ASAICharacter()
{
    PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>("PawnSensingComp");
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

    AttributeComp = CreateDefaultSubobject<USAttributeComponent>("AttributeComp");

    TimeToHitParamName = "TimeToHit";
}



void ASAICharacter::PostInitializeComponents()
{
    Super::PostInitializeComponents();
    PawnSensingComp->OnSeePawn.AddDynamic(this, &ASAICharacter::OnPawnSeen);

    AttributeComp->OnHealthChanged.AddDynamic(this, &ASAICharacter::OnHealthChanged);
}

void ASAICharacter::SetTargetActor(AActor* NewTarget)
{
    AAIController* AIC = Cast<AAIController>(GetController());
    if (AIC)
    {
        AIC->GetBlackboardComponent()->SetValueAsObject("TargetActor", NewTarget);
    }
}

void ASAICharacter::OnPawnSeen(APawn* Pawn)
{
    SetTargetActor(Pawn);

    DrawDebugString(GetWorld(), GetActorLocation(), "PlayerSpotted", nullptr, FColor::Red, 4.0f, true);
    
}

void ASAICharacter::OnHealthChanged(AActor* InstigatorActor, USAttributeComponent* OwningComp, float NewHealth, float Delta)
{
    if (Delta < 0.0f)
    {
        if (InstigatorActor != this)
        {
            SetTargetActor(InstigatorActor);
            GEngine->AddOnScreenDebugMessage(-1,2.0f,FColor::Red,FString::Printf(TEXT("SAICharacter.cpp: Got hit and Aiming")));
        }

        GetMesh()->SetScalarParameterValueOnMaterials(TimeToHitParamName, GetWorld()->TimeSeconds);

        if (NewHealth <= 0.0f)
        {
            //stop BT
            AAIController* AIC = Cast<AAIController>(GetController());
            if (AIC)
            {
                AIC->GetBrainComponent()->StopLogic("Killed");
            }
            
            //ragdoll
            GetMesh()->SetAllBodiesSimulatePhysics(true);
            GetMesh()->SetCollisionProfileName("Ragdoll");

            //set lifespan
            SetLifeSpan(10.0f);
        }
    }
}

