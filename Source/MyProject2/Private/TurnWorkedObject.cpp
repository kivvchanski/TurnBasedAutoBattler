// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnWorkedObject.h"

// Sets default values
ATurnWorkedObject::ATurnWorkedObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATurnWorkedObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATurnWorkedObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ATurnWorkedObject::PassTurn() 
{
	OnTurnPassed.Broadcast();
}

ATurnWorkedObject* ATurnWorkedObject::MakeTurnObject(FString name)
{
	ATurnWorkedObject* Obj = NewObject<ATurnWorkedObject>();
	Obj->ObjectName = name;
	return Obj;
}
void ATurnWorkedObject::MakeTurn_Implementation()
{
	
	UE_LOG(LogTemp, Warning, TEXT("Default MakeTurn in C++"));
}

void ATurnWorkedObject::CallMakeTurn()
{
	MakeTurn();
}




