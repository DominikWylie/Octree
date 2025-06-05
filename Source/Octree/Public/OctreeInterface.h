// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UCLASS()
class OCTREE_API UOctreeInterface : public UInterface
{
	GENERATED_BODY()
};

class OCTREE_API IOctreeInterface 
{
	GENERATED_BODY()

public:
	virtual FVector GetPosition() = 0;
};
