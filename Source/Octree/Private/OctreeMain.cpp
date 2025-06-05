// Fill out your copyright notice in the Description page of Project Settings.


#include "OctreeMain.h"

// Sets default values
AOctreeMain::AOctreeMain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

#if WITH_EDITOR
	BoundingBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoundingBox"));

	BoundingBox->SetBoxExtent(FVector(100.f, 100.f, 100.f));
	BoundingBox->SetRelativeLocation(FVector::ZeroVector);

	BoundingBox->ShapeColor = FColor::Green;
#endif
}

// Called when the game starts or when spawned
void AOctreeMain::BeginPlay()
{
	Super::BeginPlay();
	
}

void AOctreeMain::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

#if WITH_EDITOR
	FVector WorldLocation = Transform.GetLocation();

	FVector CentreLocation = ((FirstCorner + WorldLocation) + (SecondCorner + WorldLocation)) * 0.5f;
	FVector BoxExtents = ((SecondCorner + WorldLocation) - (FirstCorner + WorldLocation)).GetAbs() * 0.5f;

	BoundingBox->SetRelativeLocation(CentreLocation);
	BoundingBox->SetBoxExtent(BoxExtents);

	BoundingBox->SetVisibility(bBoundingBoxVisibiliy);
#endif
}

// Called every frame
void AOctreeMain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

