// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperSpriteComponent.h"
#include "LucidGameInstance.h"
#include "PuzzleLevel.h"
#include "Truck.generated.h"

UCLASS()
class LUCID_API ATruck : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATruck();
	void Initialize(FIntPoint startingPoint, int startDelay, FString route);

	UFUNCTION(BlueprintCallable)
		const FVector2D& GetPosition() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector2D _position;
	int _startDelay;
	FString _route;

};
