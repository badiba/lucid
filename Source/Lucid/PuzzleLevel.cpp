// Fill out your copyright notice in the Description page of Project Settings.


#include "XmlFile.h"
#include "PuzzleLevel.h"
#include "Truck.h"

// Sets default values
APuzzleLevel::APuzzleLevel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	_width = 0;
	_height = 0;
}

void APuzzleLevel::Deserialize(const FString& path)
{
	FXmlFile xmlFile(path);

	if (ensureMsgf(xmlFile.IsValid(), TEXT("Unable to deserialize puzzle level object using the file %s"), *path))
	{
		const FXmlNode* root = xmlFile.GetRootNode();

		for (const FXmlAttribute& attribute : root->GetAttributes())
		{
			const FString& tag = attribute.GetTag();
			
			if (tag == FString("width"))
			{
				_width = FCString::Atoi(*attribute.GetValue());
			}
			else if (tag == FString("height"))
			{
				_height = FCString::Atoi(*attribute.GetValue());
			}
		}

		for (const FXmlNode* child : root->GetChildrenNodes())
		{
			const FString& childName = child->GetTag();

			if (childName == FString("point"))
			{
				int positionX = -1;
				int positionY = -1;

				for (const FXmlAttribute& attribute : child->GetAttributes())
				{
					const FString& attributeName = attribute.GetTag();

					if (attributeName == FString("positionx"))
					{
						positionX = FCString::Atoi(*attribute.GetValue());
					}
					else if (attributeName == FString("positiony"))
					{
						positionY = FCString::Atoi(*attribute.GetValue());
					}
				}

				if (ensureMsgf(positionX >= 0 && positionX < _width && positionY >= 0 && positionY < _height,
					TEXT("Given point is outside of level boundaries. Point position: <%d %d>"), positionX, positionY))
				{
					_points.Add(FIntPoint(positionX, positionY));
				}
			}
			else if (childName == FString("destination"))
			{
				
			}
			else if (childName == FString("truck"))
			{
				int pointIndex = -1;
				int startDelay = -1;
				FString route;

				for (const FXmlAttribute& attribute : child->GetAttributes())
				{
					const FString& attributeName = attribute.GetTag();

					if (attributeName == FString("pointindex"))
					{
						pointIndex = FCString::Atoi(*attribute.GetValue());
					}
					else if (attributeName == FString("startdelay"))
					{
						startDelay = FCString::Atoi(*attribute.GetValue());
					}
					else if (attributeName == FString("route"))
					{
						route = attribute.GetValue();
					}
				}

				if (ensureMsgf(pointIndex >= 0 && pointIndex < _points.Num() && startDelay >= 0 && !route.IsEmpty(),
					TEXT("Given truck definition is incorrect. PointIndex: %d, StartDelay: %d, Route: %s"), pointIndex, startDelay, *route))
				{
					UWorld* world = GetWorld();
					FActorSpawnParameters spawnParameters;
					FTransform transform(FRotator(0, 0, 0), FVector(0, 5, 0), FVector(0.25f, 0.25f, 0.25f));
					ATruck* truck = world->SpawnActor<ATruck>(TruckBlueprint, transform, spawnParameters);
					truck->Initialize(_points[pointIndex], startDelay, route);
					_trucks.Add(truck);
				}
			}
		}
	}
}

const TArray<FIntPoint>& APuzzleLevel::GetPoints() const
{
	return _points;
}

const TArray<ATruck*>& APuzzleLevel::GetTrucks() const
{
	return _trucks;
}

// Called when the game starts or when spawned
void APuzzleLevel::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APuzzleLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

