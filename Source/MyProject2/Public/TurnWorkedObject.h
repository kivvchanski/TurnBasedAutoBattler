// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TurnWorkedObject.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPassTurn);
UCLASS()
class MYPROJECT2_API ATurnWorkedObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurnWorkedObject();
	FOnPassTurn OnTurnPassed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TurnSystem")
	FString ObjectName;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = "TurnSystem")
	void PassTurn();
	UFUNCTION (BlueprintCallable, Category="TurnSystem")
	static ATurnWorkedObject* MakeTurnObject(FString name);
	UFUNCTION(BlueprintNativeEvent, Category = "TurnSystem")
	void MakeTurn();
	virtual void MakeTurn_Implementation();
	UFUNCTION(BlueprintCallable, Category = "TurnSystem")
	void CallMakeTurn();
};
