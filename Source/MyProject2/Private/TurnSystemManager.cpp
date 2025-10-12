// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnSystemManager.h"
#include "TurnWorkedObject.h"

// Sets default values
ATurnSystemManager::ATurnSystemManager()
{

	PrimaryActorTick.bCanEverTick = true;

}

TArray<ATurnWorkedObject*> ATurnSystemManager::GetFightIncludedObjects()
{
	return FightIncludedObjects;
}

// Called when the game starts or when spawned
void ATurnSystemManager::BeginPlay()
{
	Super::BeginPlay();
	ActivePlayerNum = 0;
	
}

// Called every frame
void ATurnSystemManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATurnSystemManager::AddObjectInFight(ATurnWorkedObject* NewFighter) {
	FightIncludedObjects.AddUnique(NewFighter);
	NewFighter->OnTurnPassed.AddDynamic(this, &ATurnSystemManager::NextTurnIteration);
}
template <typename T, typename Field>
void SortFightersByParam(TArray<T> SortArray, Field T ::* field) 
{
	
}
ATurnSystemManager* ATurnSystemManager::MakeTurnSystemManager()
{
	ATurnSystemManager* Obj = NewObject<ATurnSystemManager>();
	return Obj;
}

void ATurnSystemManager::ClearFighters() 
{

    
	for (ATurnWorkedObject* Obj : FightIncludedObjects) 
	{
		Obj->OnTurnPassed.RemoveDynamic(this, &ATurnSystemManager::NextTurnIteration);
	}
      FightIncludedObjects.Empty();
	  ActivePlayerNum = 0;
}

void ATurnSystemManager::NextTurnIteration()
{
	if (ActivePlayerNum + 1 < FightIncludedObjects.Num()) {
		ActivePlayerNum++;
		ATurnWorkedObject* ActiveObject = FightIncludedObjects[ActivePlayerNum];
		ActiveObject->MakeTurn();
	}
	else if (FightIncludedObjects.Num() > 1) {
		ActivePlayerNum = 0;
		FightIncludedObjects[0]->MakeTurn();
	}
	else {
		ActivePlayerNum = 0;
	}
}

void ATurnSystemManager::OnPlayerDeath(ATurnWorkedObject* DeadObject)
{
	FightIncludedObjects.Remove(DeadObject);
}
