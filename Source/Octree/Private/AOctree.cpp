// Fill out your copyright notice in the Description page of Project Settings.


#include "AOctree.h"

// Sets default values
AAOctree::AAOctree()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAOctree::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAOctree::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

