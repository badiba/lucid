// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LucidGameInstance.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/IntPoint.h"
#include "PuzzleLevel.generated.h"

class ATruck;

UCLASS()
class LUCID_API APuzzleLevel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APuzzleLevel();

	const TArray<FIntPoint>& GetPoints() const;
	const TArray<class ATruck*>& GetTrucks() const;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ATruck> TruckBlueprint;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Deserialize(const FString& path);

private:
	TArray<class ATruck*> _trucks;
	TArray<FIntPoint> _points;
	int _width;
	int _height;

};
