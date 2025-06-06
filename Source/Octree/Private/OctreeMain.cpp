// Fill out your copyright notice in the Description page of Project Settings.


#include "OctreeMain.h"

// Sets default values
AOctreeMain::AOctreeMain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

#if WITH_EDITOR
	bRunConstructionScriptOnDrag = true; //for visual updates while moving in editor
#endif
}

void AOctreeMain::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
}

void AOctreeMain::DrawBox()
{
	if (!bBoundingBoxVisibiliy) {
		return;
	}

	FVector WorldLoc = GetActorLocation();

	DrawDebugBox(GetWorld(), ((SecondCorner + WorldLoc) + (FirstCorner + WorldLoc)) / 2, (FirstCorner - SecondCorner) / 2, FColor::Red);

	//DrawDebugBox(GetWorld(), ((SecondCorner) + (FirstCorner)) / 2, (FirstCorner - SecondCorner) / 2, FColor::Red);

}

void AOctreeMain::Tick(float DeltaTime)
{
	if (IsRunningGame()) {
		Super::Tick(DeltaTime);
	}

#if WITH_EDITOR
		DrawBox();
#endif
}

