// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "PCGLevel.generated.h"

UCLASS()
class TESTPRCPROJ_API APCGLevel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APCGLevel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Properties
	UPROPERTY(EditAnywhere) int length;
	UPROPERTY(EditAnywhere) int width;

	UPROPERTY(EditAnywhere) float floorHeightScale;
	UPROPERTY(EditAnywhere) float wallWidthScale;

	UPROPERTY(EditAnywhere) float tileStepScale;

	UPROPERTY(EditAnywhere) UHierarchicalInstancedStaticMeshComponent* floorMesh;

	void BuildFloor();
};
