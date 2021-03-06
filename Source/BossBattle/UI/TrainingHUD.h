// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TrainingHUD.generated.h"

/**
 * 
 */
UCLASS()
class BOSSBATTLE_API ATrainingHUD : public AHUD
{
	GENERATED_BODY()
private:
	void PostInitializeComponents() override;

	//training stats widget
	UPROPERTY(EditDefaultsOnly, Category = UI)
	TSubclassOf<class UTrainingStatsWidget> TrainingStatsWidgetTemplate;

	//training stats widget template
	class UTrainingStatsWidget* TrainingStatsWidget = nullptr;

	
};
