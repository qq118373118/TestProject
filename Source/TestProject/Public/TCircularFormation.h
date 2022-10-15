// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TFormationBase.h"
#include "TCircularFormation.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TESTPROJECT_API UTCircularFormation : public UTFormationBase
{
	GENERATED_BODY()

public:

	virtual void CreateFormation(TArray<ATBaseSoldier*> SoliderList) override;

	void Calculate(int Count);

	UPROPERTY(BlueprintReadOnly)
	float R;

	UPROPERTY(BlueprintReadOnly)
	FVector CPoint;

	UPROPERTY(BlueprintReadOnly)
	float Radians;

};
