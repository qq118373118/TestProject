// Fill out your copyright notice in the Description page of Project Settings.


#include "THUD.h"
#include "TBaseSoldier.h"
#include "GameFramework/HUD.h"
#include "TPlayerController.h"

void ATHUD::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = Cast<ATPlayerController>(GetOwningPlayerController());

	bSelectPostion = false;
}

void ATHUD::DrawHUD()
{

	FVector2D CurrentPoint = GetMousePoint();

	if(bSelectPostion)
	{
		DrawRect(FLinearColor(0,0,0,0.15f), MouseClickPostion.X, MouseClickPostion.Y,
			CurrentPoint.X - MouseClickPostion.X, CurrentPoint.Y - MouseClickPostion.Y);

		//��ȡActor�����Ḳ��ԭ�������ݣ����ǲ�����ԭ�������ݺ������.
		//���Ի�ȡ����֮ǰ��Ҫ�����ݸ����

		SoliderList.Empty();
		GetActorsInSelectionRectangle<ATBaseSoldier>(MouseClickPostion, CurrentPoint, SoliderList,false,false);
	}

}

FVector2D ATHUD::GetMousePoint()
{
	float x, y;
	PlayerController->GetMousePosition(x, y);
	return FVector2D(x, y);
}

TArray<ATBaseSoldier*>  ATHUD::GetSoliderList() const
{
	return SoliderList;
}