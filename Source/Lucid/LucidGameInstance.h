// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "LucidGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class LUCID_API ULucidGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere)
		class ALucidGame* CurrentGame;
};
