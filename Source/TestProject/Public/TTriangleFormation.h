// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TFormationBase.h"
#include "TTriangleFormation.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TESTPROJECT_API UTTriangleFormation : public UTFormationBase
{
	GENERATED_BODY()

public:
	virtual void CreateFormation(TArray<ATBaseSoldier*> SoliderList) override;

	void Calculate();

	float Radians;
	
};
