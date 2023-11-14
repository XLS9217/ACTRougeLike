// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/SAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void ASAIController::BeginPlay()
{
	Super::BeginPlay();

	if (ensureMsgf(BehaviorTree, TEXT("Behavior Tree is null, please assign behavior tree in AI Controller")))
	{
		RunBehaviorTree(BehaviorTree);
	}

	//APawn* MyPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	//if (MyPawn) 
	//{
	//	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("MyPawn exist")));
	//	GetBlackboardComponent()->SetValueAsVector("MoveToLocation",MyPawn->GetActorLocation());
	//	GetBlackboardComponent()->SetValueAsObject("TargetActor", MyPawn);
	//}
}
