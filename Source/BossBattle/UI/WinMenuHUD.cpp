// Fill out your copyright notice in the Description page of Project Settings.


#include "WinMenuHUD.h"


#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"


#include "UI/WinMenuWidget.h"
#include "Utilities/CustomMacros.h"

void AWinMenuHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	LoadWinMenuWidget();

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (validate(IsValid(PlayerController)) == false) return;

	UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(PlayerController, WinMenuWidget, EMouseLockMode::DoNotLock);


	PlayerController->bShowMouseCursor = true;

}

void AWinMenuHUD::LoadWinMenuWidget()
{
	if (validate(IsValid(WinMenuWidgetTemplate)) == false) { return; }

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	WinMenuWidget = Cast<UWinMenuWidget>(CreateWidget(World, WinMenuWidgetTemplate));
	if (validate(IsValid(WinMenuWidget)) == false) { return; }


	WinMenuWidget->AddToViewport();
}
