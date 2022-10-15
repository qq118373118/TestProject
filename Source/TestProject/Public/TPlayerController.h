// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TPlayerController.generated.h"

class UInputComponent;
class ATHUD;
class ATBaseSoldier;
class UTFormationBase;
class ATPlayerPawn;
class USpringArmComponent;

/**
 * 
 */
UCLASS()
class TESTPROJECT_API ATPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

	void ClearState();

protected:

	ATHUD* MyHUD;

	ATPlayerPawn* PlayerPawn;

	USpringArmComponent* SpringArmComp;

	//当前选中队伍中领队的下标
	int CurrentIndex;

	void MouseLeftButtonPressed();

	void MouseLeftButtonReleaseed();

	void MouseRightButtonPressed();

	void MoveForward(float Value);

	void MoveRight(float Value);

	void InitFormation();

	float MovementSpeedCalculation() const;

	void ZoomIn();

	void ZoomOut();

	void Initialization();

	UFUNCTION(BlueprintCallable)
	void AddDiraction();

	UFUNCTION(BlueprintCallable)
	void MinusDiraction();

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<UTFormationBase>> FormationClass;

	UPROPERTY(BlueprintReadOnly)
	TArray<UTFormationBase*> Formations;

	UPROPERTY(BlueprintReadOnly)
	TArray<ATBaseSoldier*> SoliderList;

	UFUNCTION(BlueprintCallable)
	void UseFormation(int index);

	UFUNCTION(BlueprintCallable)
	void UseRemoveComp(int index);

	UPROPERTY(BlueprintReadWrite)
	int FormationIndex;

};
