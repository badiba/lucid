// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Truck.h"
#include "Blueprint/UserWidget.h"
#include "MainWidget.generated.h"

/**
 * 
 */
UCLASS()
class LUCID_API UMainWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintImplementableEvent)
		void CreateTruckWidget(ATruck* truck);

	UFUNCTION(BlueprintImplementableEvent)
		void CreatePoint(FIntPoint point);
};
