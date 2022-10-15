// Fill out your copyright notice in the Description page of Project Settings.


#include "TTriangleFormation.h"

void UTTriangleFormation::CreateFormation(TArray<ATBaseSoldier*> SoliderList)
{

	if(SoliderList.Num()<=0)
	{
		return;
	}

	Leader = SoliderList[0];

	int Count = SoliderList.Num();

	Calculate();

	int n = 1;
	int j = 0;

	for(int i = 1;i<Count;++i)
	{
		float X = -FMath::Cos(Radians) * Diraction * n;

		float Y = (-n * Diraction * FMath::Sin(Radians)) / 2 + j * Diraction;

		if(j<=n)
		{
			FVector TargetLocation = FVector(X, Y, 0);

			FTransform TargetTransform(FRotator::ZeroRotator, TargetLocation);

			SetComponent(SoliderList[i], TargetTransform);

			++j;

			if(j>n)
			{
				j = 0;
				++n;
			}
		}

	}
}

void UTTriangleFormation::Calculate()
{
	Radians = FMath::DegreesToRadians(30.f);
}

