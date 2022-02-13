// Fill out your copyright notice in the Description page of Project Settings.

#include "Blueprint/UserWidget.h"
#include "PuzzleLevel.h"
#include "MainWidget.h"
#include "Truck.h"
#include "LucidGame.h"

// Sets default values
ALucidGame::ALucidGame()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALucidGame::BeginPlay()
{
	Super::BeginPlay();

	ULucidGameInstance* gameInstance = GetGameInstance<ULucidGameInstance>();
	gameInstance->CurrentGame = this;

	UWorld* world = GetWorld();
	UMainWidget* mainWidget = Cast<UMainWidget>(CreateWidget(world, MainWidgetBP));
	mainWidget->AddToViewport();

	CurrentLevel = world->SpawnActor<APuzzleLevel>(PuzzleLevelBP, FTransform(), FActorSpawnParameters());
	CurrentLevel->Deserialize(FPaths::ProjectContentDir() + TEXT("PuzzleLevels/TestLevel.xml"));

	for (const auto& point : CurrentLevel->GetPoints())
	{
		mainWidget->CreatePoint(point);
	}

	for (const auto& truck : CurrentLevel->GetTrucks())
	{
		mainWidget->CreateTruckWidget(truck);
	}
}

// Called every frame
void ALucidGame::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
