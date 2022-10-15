// Fill out your copyright notice in the Description page of Project Settings.


#include "TBaseSoldier.h"

#include "Blueprint/AIBlueprintHelperLibrary.h"

// Sets default values
ATBaseSoldier::ATBaseSoldier()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MoveLocation = nullptr;
}

// Called when the game starts or when spawned
void ATBaseSoldier::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATBaseSoldier::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(MoveLocation!=nullptr)
	{
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this->GetController(), MoveLocation->GetComponentLocation());
	}
}

void ATBaseSoldier::ChangeRander(bool state)
{
	GetMesh()->SetRenderCustomDepth(state);
}


