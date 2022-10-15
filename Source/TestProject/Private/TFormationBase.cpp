// Fill out your copyright notice in the Description page of Project Settings.


#include "TFormationBase.h"
#include "TBaseSoldier.h"

//根据策略模式，生成对应的阵型
void UTFormationBase::CreateFormation(TArray<ATBaseSoldier*> SoliderList)
{
	//由子类继承并实现改阵型SceneComponent的位置
}

void UTFormationBase::RemoveComp(TArray<ATBaseSoldier*> SoliderList)
{
	if(Leader!=nullptr)
	{
		for (UActorComponent* Comp : Leader->SceneList)
		{
			Comp->DestroyComponent();
		}
		Leader->SceneList.Empty();

		Leader = nullptr;
	}

	for(int i = 0;i<SoliderList.Num();++i)
	{
		SoliderList[i]->MoveLocation = nullptr;
	}
}

UTFormationBase::UTFormationBase()
{
	Diraction = 200.f;
	Leader = nullptr;
}

void UTFormationBase::SetComponent(ATBaseSoldier* Target, FTransform TargetTransform)
{
	UActorComponent* TempComp = Leader->AddComponentByClass(USceneComponent::StaticClass(), false, TargetTransform, false);
	Target->MoveLocation = Cast<USceneComponent>(TempComp);
	Leader->SceneList.Add(TempComp);
}
