// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "THUD.generated.h"

class ATBaseSoldier;
class ATPlayerController;

/**
 * 
 */
UCLASS()
class TESTPROJECT_API ATHUD : public AHUD
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

	virtual void DrawHUD() override;

	FVector2D MouseClickPostion;
	
	FVector2D GetMousePoint();

	void Draw();


	bool bSelectPostion;

	UFUNCTION(BlueprintCallable)
	TArray<ATBaseSoldier*> GetSoliderList() const;

protected:

	ATPlayerController* PlayerController;

	TArray<ATBaseSoldier*> SoliderList;

};
