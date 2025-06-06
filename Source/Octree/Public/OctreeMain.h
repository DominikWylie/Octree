// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"

#include "OctreeMain.generated.h"

UCLASS()
class OCTREE_API AOctreeMain : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOctreeMain();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (MakeEditWidget = true))
	FVector FirstCorner = FVector(50.f, 50.f, 50.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (MakeEditWidget = true))
	FVector SecondCorner = FVector(-50.f, -50.f, 50.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bBoundingBoxVisibiliy = true;

private:

	//virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform) override;

	virtual void Tick(float DeltaTime) override;

#if WITH_EDITOR
	//virtual void Tick(float DeltaTime) override;
	virtual bool ShouldTickIfViewportsOnly() const override { return true; }
#endif

	void DrawBox();

	//todo
	//create lightweight debug box system for seeing the octree in editor and in game (that can be turned off and on)
	//create custom AABB collision for axis alighned efficiancy
};
