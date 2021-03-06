// Fill out your copyright notice in the Description page of Project Settings.


#include "TrainingWidget.h"


#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/Button.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

#include "Utilities/CustomMacros.h"
#include "UI/MainMenuHUD.h"

void UTrainingWidget::NativeConstruct()
{

	Super::NativeConstruct();

	if (validate(IsValid(BackButton))) {
		BackButton->OnClicked.AddDynamic(this, &UTrainingWidget::Back);
	}
	if (validate(IsValid(AITrainingButton))) {
		AITrainingButton->OnClicked.AddDynamic(this, &UTrainingWidget::LoadAITraining);
	}
	
}

void UTrainingWidget::Back()
{
	APlayerController* PlayerController = GetOwningPlayer();
	if (validate(IsValid(PlayerController)) == false) { return; }

	AMainMenuHUD* MainMenuHUD = Cast<AMainMenuHUD>(PlayerController->GetHUD());
	if (validate(IsValid(MainMenuHUD)) == false) { return; }

	MainMenuHUD->LoadMainMenu();

}

void UTrainingWidget::LoadAITraining()
{
	UWorld* World = GetWorld();

	if (validate(IsValid(World)) == false) { return; }
	if (validate(AITrainingLevelName.ToString().Len() > 0) == false) { return; }


	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (validate(IsValid(PlayerController)) == false) return;

	UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(PlayerController);

	UGameplayStatics::OpenLevel(World, AITrainingLevelName);
}
