// Fill out your copyright notice in the Description page of Project Settings.


#include "TSquareFormation.h"
#include "TBaseSoldier.h"

void UTSquareFormation::CreateFormation(TArray<ATBaseSoldier *>  SoliderList)
{
	if(SoliderList.Num()<=1)
	{
		return;
	}

	int SoliderCount = SoliderList.Num();
	int x = Calculate(SoliderCount);

	//设置该阵型领队
	int Index = x / 2;
	Leader = SoliderList[Index];

	int LearderRow = Index / x;
	int LearderColumn = Index % x;


	FRotator LearderRotator = Leader->GetActorRotation();

	for(int i = 0;i<SoliderCount;++i)
	{
		if(i== Index)
		{
			continue;
		}

		int Row = LearderRow - (i / x);
		int Column = LearderColumn - (i % x);

		FVector TargetLocation = FVector(Row * Diraction, Column * Diraction, 0.f);

		FTransform TargetTransform( LearderRotator, TargetLocation);

		//UActorComponent * TempComp = Leader->AddComponentByClass(USceneComponent::StaticClass(), false, TargetTransform, false);
		//SoliderList[i]->MoveLocation = Cast<USceneComponent>(TempComp);
		//Leader->SceneList.Add(TempComp);
		SetComponent(SoliderList[i], TargetTransform);
	}
}

int UTSquareFormation::Calculate(int Count)
{
	return FMath::CeilToInt(sqrt(Count));
}
