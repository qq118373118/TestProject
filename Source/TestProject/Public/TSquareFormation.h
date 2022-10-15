// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TFormationBase.h"
#include "TSquareFormation.generated.h"

/**
 * 
 */
//���ûдBlueprtable���޷��ٱ༭���н���������ͼ
UCLASS(Blueprintable)
class TESTPROJECT_API UTSquareFormation : public UTFormationBase
{
	GENERATED_BODY()

public:

	virtual void CreateFormation(TArray<ATBaseSoldier*> SoliderList) override;


	//���㷽�󵥱�����
	int Calculate(int Count);


};
