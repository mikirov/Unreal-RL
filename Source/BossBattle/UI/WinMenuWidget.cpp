// Fill out your copyright notice in the Description page of Project Settings.


#include "WinMenuWidget.h"

#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/World.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

#include "Utilities/CustomMacros.h"

void UWinMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (ServerAddress.IsEmpty()) {
		ServerAddress = "185.20.159.64";
	}

	if (MainMenuLevelName == FName("")) {
		MainMenuLevelName = FName(TEXT("MainMenu"));
	}
	
	if (validate(IsValid(RestartGameButton))) {
		RestartGameButton->OnPressed.AddDynamic(this, &UWinMenuWidget::RestartGame);
	}
	if (validate(IsValid(QuitButton))) {
		QuitButton->OnReleased.AddDynamic(this, &UWinMenuWidget::QuitGame);
	}
	if (validate(IsValid(MainMenuButton))) {
		MainMenuButton->OnPressed.AddDynamic(this, &UWinMenuWidget::LoadMainMenu);
	}

}

void UWinMenuWidget::SetInputModeGameOnly()
{
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (validate(IsValid(PlayerController)) == false) return;

	UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerController);
}

void UWinMenuWidget::QuitGame()
{
	UWorld* World = GetWorld();
	APlayerController* Player = GetOwningPlayer();

	if (validate(IsValid(World)) && validate(IsValid(Player))) {
		UKismetSystemLibrary::QuitGame(World, Player, EQuitPreference::Quit, true);
	}
}

void UWinMenuWidget::RestartGame()
{
	if (validate(ServerAddress.Len() > 0) == false) return;
	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }
	
	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (validate(IsValid(PlayerController)) == false) return;

	UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerController);
	PlayerController->bShowMouseCursor = false;

	PlayerController->ClientTravel(ServerAddress, ETravelType::TRAVEL_Absolute);

}

void UWinMenuWidget::LoadMainMenu()
{
	if (validate(MainMenuLevelName.ToString().Len() > 0) == false) return;

	UWorld* World = GetWorld();
	if (validate(IsValid(World)) == false) { return; }

	UGameplayStatics::OpenLevel(World, MainMenuLevelName);
}
