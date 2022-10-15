// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TFormationBase.h"
#include "TSquareFormation.generated.h"

/**
 * 
 */
//如果没写Blueprtable，无法再编辑器中将该类变成蓝图
UCLASS(Blueprintable)
class TESTPROJECT_API UTSquareFormation : public UTFormationBase
{
	GENERATED_BODY()

public:

	virtual void CreateFormation(TArray<ATBaseSoldier*> SoliderList) override;


	//计算方阵单边人数
	int Calculate(int Count);


};
