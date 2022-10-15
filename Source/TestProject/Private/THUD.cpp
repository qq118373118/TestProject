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

		//获取Actor并不会覆盖原数组数据，而是不断在原数组数据后面添加.
		//所以获取数据之前需要把数据给清空

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