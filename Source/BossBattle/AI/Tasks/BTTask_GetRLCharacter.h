// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI/Tasks/BTTask_BaseBlackboardTask.h"
#include "BTTask_GetRLCharacter.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API UBTTask_GetRLCharacter : public UBTTask_BaseBlackboardTask
{
	GENERATED_BODY()
protected:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;


	class ARLEnemyCharacter* GetRLCharacter();
};
