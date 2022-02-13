// Fill out your copyright notice in the Description page of Project Settings.

#include "Truck.h"

// Sets default values
ATruck::ATruck()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATruck::BeginPlay()
{
	Super::BeginPlay();
}

void ATruck::Initialize(FIntPoint startingPoint, int startingDelay, FString route)
{
	_position = startingPoint;
	_startDelay = startingDelay;
	_route = route;
}

// Called every frame
void ATruck::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

const FVector2D& ATruck::GetPosition() const
{
	return _position;
}