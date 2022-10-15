// Fill out your copyright notice in the Description page of Project Settings.


#include "TCircularFormation.h"

void UTCircularFormation::CreateFormation(TArray<ATBaseSoldier*> SoliderList)
{


	if(SoliderList.Num()<=0)
	{
		return;
	}
	int Count = SoliderList.Num();


	Leader = SoliderList[0];
	Calculate(Count);

	for(int i = 1;i<SoliderList.Num();i++)
	{
		float Theta = Radians * i;
		float Y = R * FMath::Sin(Theta) + CPoint.Y;
		float X = R * FMath::Cos(Theta) + CPoint.X;

		FVector TargetLocation = FVector(X,Y,0);

		FTransform TargetTransform(FRotator::ZeroRotator, TargetLocation);

		SetComponent(SoliderList[i], TargetTransform);
	}
}

void UTCircularFormation::Calculate(int Count)
{
	float Theta = 360.f / Count;

	Radians = FMath::DegreesToRadians(Theta);

	R = Diraction / (FMath::Sin(Radians / 2) * 2);

	CPoint = FVector(-R, 0,0) ;

}
