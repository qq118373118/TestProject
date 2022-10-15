// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TBaseSoldier.generated.h"

UCLASS()
class TESTPROJECT_API ATBaseSoldier : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATBaseSoldier();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ChangeRander(bool state);

	UPROPERTY(BlueprintReadOnly)
	USceneComponent* MoveLocation;

	UPROPERTY(BlueprintReadOnly)
	TArray<UActorComponent*>SceneList;

};
