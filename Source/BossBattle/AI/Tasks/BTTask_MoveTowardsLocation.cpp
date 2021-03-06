// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_MoveTowardsLocation.h"

#include "BehaviorTree/BlackboardComponent.h"

#include "Utilities/CustomMacros.h"
#include "Characters/AIEnemyCharacter.h"

EBTNodeResult::Type UBTTask_MoveTowardsLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (Super::ExecuteTask(OwnerComp, NodeMemory) != EBTNodeResult::Succeeded) {
		return EBTNodeResult::Failed;
	}

	TargetLocation = BlackboardComponent->GetValueAsVector(GetSelectedBlackboardKey());
	
	FVector Direction = TargetLocation - AICharacter->GetActorLocation();
	Direction.Normalize();
	AICharacter->Move(Direction);
	
	return EBTNodeResult::Succeeded;
}
