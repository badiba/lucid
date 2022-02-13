// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LucidGame.generated.h"

UCLASS()
class LUCID_API ALucidGame : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALucidGame();

	UPROPERTY(EditAnywhere)
		TSubclassOf<class UMainWidget> MainWidgetBP;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class APuzzleLevel> PuzzleLevelBP;

	UPROPERTY(EditAnywhere)
		class APuzzleLevel* CurrentLevel;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
