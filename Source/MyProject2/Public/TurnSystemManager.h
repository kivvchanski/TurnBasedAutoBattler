// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <TurnWorkedObject.h>
#include "TurnSystemManager.generated.h"




UCLASS()
class MYPROJECT2_API ATurnSystemManager : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Sets default values for this actor's properties
	ATurnSystemManager();
	UFUNCTION(BlueprintCallable, Category="TurnSystem")
	TArray<ATurnWorkedObject*> GetFightIncludedObjects();
	UFUNCTION(BlueprintCallable, Category = "TurnSystem")
	void AddObjectInFight(ATurnWorkedObject* NewFighter);
	UFUNCTION(BlueprintCallable, Category = "TurnSystem")
	void ClearFighters();

	UFUNCTION(BlueprintCallable, Category = "TurnSystem")
	void NextTurnIteration();

	UFUNCTION(BlueprintCallable, Category = "TurnSystem")
	void OnPlayerDeath(ATurnWorkedObject* DeadObject);



	


private:
	int32 ActivePlayerNum;
	




public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TurnSystem")

	TArray<ATurnWorkedObject*> FightIncludedObjects;
	UFUNCTION(BlueprintCallable, Category = "TurnSystem")
	static ATurnSystemManager* MakeTurnSystemManager();


};


