// Fill out your copyright notice in the Description page of Project Settings.


#include "AOctree.h"

// Sets default values
AAOctree::AAOctree()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	BoundingBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoundingBox"));

	BoundingBox->SetBoxExtent(FVector(100.f, 100.f, 100.f));
	BoundingBox->SetRelativeLocation(FVector::ZeroVector);
}

// Called when the game starts or when spawned
void AAOctree::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAOctree::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	FVector WorldLocation = Transform.GetLocation();

	FVector CentreLocation = ((FirstCorner + WorldLocation) + (SecondCorner + WorldLocation)) * 0.5f;
	FVector BoxExtents = ((SecondCorner + WorldLocation) - (FirstCorner + WorldLocation)).GetAbs() * 0.5f;
	
	BoundingBox->SetRelativeLocation(CentreLocation);
	BoundingBox->SetBoxExtent(BoxExtents);

	BoundingBox->SetVisibility(bBoundingBoxVisibiliy);
}

// Called every frame
void AAOctree::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

