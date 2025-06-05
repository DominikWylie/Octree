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

#if WITH_EDITORONLY_DATA
	//editor macro only
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoundingBox;
#endif

	//USceneComponent* MyRootComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
