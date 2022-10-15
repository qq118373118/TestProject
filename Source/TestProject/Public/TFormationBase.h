// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TBaseSoldier.h"
#include "TFormationBase.generated.h"

class ATBaseSoldier;

/**
 * 
 */
UCLASS()
class TESTPROJECT_API UTFormationBase : public UObject
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable)
	virtual void CreateFormation(TArray<ATBaseSoldier*> SoliderList);

	void RemoveComp(TArray<ATBaseSoldier*> SoliderList);

	UPROPERTY(BlueprintReadWrite)
	float Diraction;

	UPROPERTY(BlueprintReadOnly)
	ATBaseSoldier * Leader;

	UTFormationBase();

	void SetComponent(ATBaseSoldier* Target, FTransform TargetTransform);

};
