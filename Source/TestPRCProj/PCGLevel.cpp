// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "PCGLevel.h"

// Sets default values
APCGLevel::APCGLevel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	floorMesh = CreateDefaultSubobject<UHierarchicalInstancedStaticMeshComponent>(TEXT("Floor_Mesh"));
}

// Called when the game starts or when spawned
void APCGLevel::BeginPlay()
{
	Super::BeginPlay();
	
	floorMesh->RegisterComponent();
	BuildFloor();
}

// Called every frame
void APCGLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APCGLevel::BuildFloor()
{
	for (int x = 0; x < length; x++)
	{
		for (int y = 0; y < width; y++)
		{
			FTransform trans = GetTransform();
			trans.AddToTranslation(FVector(tileStepScale * x, tileStepScale * y, 0));
			trans.SetScale3D(FVector(1, 1, floorHeightScale));

			floorMesh->AddInstance(trans);
		}
	}
}