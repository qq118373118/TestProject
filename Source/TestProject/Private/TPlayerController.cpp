// Fill out your copyright notice in the Description page of Project Settings.


#include "TPlayerController.h"

#include "AIController.h"
#include "Components/InputComponent.h"
#include "THUD.h"
#include "TBaseSoldier.h"
#include "Engine/EngineTypes.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "TFormationBase.h"
#include "TPlayerPawn.h"
#include "GameFramework/SpringArmComponent.h"

void ATPlayerController::BeginPlay()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
	

	FormationIndex = -1;

	InitFormation();

	Initialization();
}

void ATPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("MouseLeftButton", IE_Pressed, this, &ATPlayerController::MouseLeftButtonPressed);
	InputComponent->BindAction("MouseLeftButton", IE_Released, this, &ATPlayerController::MouseLeftButtonReleaseed);
	InputComponent->BindAction("MouseRightButton", IE_Released, this, &ATPlayerController::MouseRightButtonPressed);

	InputComponent->BindAxis("MoveForward", this, &ATPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ATPlayerController::MoveRight);

	InputComponent->BindAction("ZoomIn", IE_Released, this, &ATPlayerController::ZoomIn);
	InputComponent->BindAction("ZoomOut", IE_Released, this, &ATPlayerController::ZoomOut);

	InputComponent->BindAction("AddDiraction", IE_Released, this, &ATPlayerController::AddDiraction);
	InputComponent->BindAction("MinusDiraction", IE_Released, this, &ATPlayerController::MinusDiraction);

}

void ATPlayerController::MouseLeftButtonPressed()
{
	ClearState();
	MyHUD->MouseClickPostion = MyHUD->GetMousePoint();
	MyHUD->bSelectPostion = true;
}

void ATPlayerController::MouseLeftButtonReleaseed()
{

	MyHUD->bSelectPostion = false;

	SoliderList = MyHUD->GetSoliderList();

	for (ATBaseSoldier* Solider : SoliderList)
	{
		Solider->ChangeRander(true);
	}

}

void ATPlayerController::MouseRightButtonPressed()
{

	FHitResult HitResult;
	TArray<TEnumAsByte<EObjectTypeQuery> > objTypes;
	objTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldStatic));


	GetHitResultUnderCursorForObjects(objTypes, true, HitResult);
	FVector TargetLocation = FVector(HitResult.ImpactPoint.X, HitResult.ImpactPoint.Y, 0.f);

	if (SoliderList.Num() > 0)
	{
		for (ATBaseSoldier* Solider : SoliderList)
		{
			//要在build文件里面添加AI模块
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(Solider->GetController(), TargetLocation);
		}
	}

}

void ATPlayerController::MoveForward(float Value)
{
	FVector PlayerLoc = PlayerPawn->GetActorLocation() + FVector(Value * MovementSpeedCalculation() * 2.0f, 0, 0);
	PlayerPawn->SetActorLocation(PlayerLoc);
}

void ATPlayerController::MoveRight(float Value)
{
	FVector PlayerLoc = PlayerPawn->GetActorLocation() + FVector(0, Value * MovementSpeedCalculation() * 2.0f, 0);
	PlayerPawn->SetActorLocation(PlayerLoc);
}

float ATPlayerController::MovementSpeedCalculation() const
{
	float length = SpringArmComp->TargetArmLength;

	return FMath::Clamp(length / 75, 5.0f, 200.0f);
}

void ATPlayerController::ZoomIn()
{
	float TargetLength = SpringArmComp->TargetArmLength - 75;

	float NewAngle = -(TargetLength - 800) * 0.041f - 25.f;

	SpringArmComp->SetRelativeRotation(FRotator(NewAngle, 0.f, 0.f));

	SpringArmComp->TargetArmLength = FMath::Clamp(TargetLength, 800.f, 2000.f);
}

void ATPlayerController::ZoomOut()
{

	float TargetLength = SpringArmComp->TargetArmLength + 75;

	float NewAngle = -(TargetLength - 800) * 0.05f - 25.f;

	SpringArmComp->SetRelativeRotation(FRotator(NewAngle, 0.f,0.f ));

	SpringArmComp->TargetArmLength = FMath::Clamp(TargetLength, 800.f, 2000.f);
}

void ATPlayerController::Initialization()
{

	MyHUD = Cast<ATHUD>(GetHUD());

	PlayerPawn = Cast<ATPlayerPawn>(GetPawn());

	SpringArmComp = Cast<USpringArmComponent>(PlayerPawn->GetComponentByClass(USpringArmComponent::StaticClass()));
}

void ATPlayerController::AddDiraction()
{
	if(FormationIndex>=0&&FormationIndex<Formations.Num())
	{
		float OldDiraction = Formations[FormationIndex]->Diraction;
		float NewDiraction =FMath::Clamp(OldDiraction + 50,100.f,300.f) ;
		Formations[FormationIndex]->Diraction = NewDiraction;
	}
}

void ATPlayerController::MinusDiraction()
{
	if (FormationIndex >= 0 && FormationIndex < Formations.Num())
	{
		float OldDiraction = Formations[FormationIndex]->Diraction;
		float NewDiraction = FMath::Clamp(OldDiraction - 50, 100.f, 300.f);
		Formations[FormationIndex]->Diraction = NewDiraction;
	}
}

void ATPlayerController::UseFormation(int index)
{
	if(index >= 0 && index < Formations.Num())
	{
		if(IsValid(Formations[index]))
		{
			Formations[index]->CreateFormation(SoliderList);
		}
	}
}

void ATPlayerController::UseRemoveComp(int index)
{
	if (index >= 0&&index<Formations.Num())
	{
		if (IsValid(Formations[index]))
		{
			Formations[index]->RemoveComp(SoliderList);
		}
	}
}

void ATPlayerController::ClearState()
{
	int n = SoliderList.Num();

	if(FormationIndex>=0&&FormationIndex< Formations.Num())
	{
		Formations[FormationIndex]->RemoveComp(SoliderList);
		FormationIndex = -1;
	}

	for (int i = 0; i < n; ++i)
	{
		SoliderList[i]->ChangeRander(false);
	}

}

void ATPlayerController::InitFormation()
{

	Formations.Empty();

	for(TSubclassOf<UTFormationBase> Formation:FormationClass)
	{
		UTFormationBase* NewFormation = NewObject<UTFormationBase>(GetOuter(), Formation);
		if(ensure(NewFormation))
		{
			Formations.Add(NewFormation);
		}
	}
}


