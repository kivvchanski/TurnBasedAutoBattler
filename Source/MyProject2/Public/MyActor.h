// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSomethingHappened);
UCLASS()
class MYPROJECT2_API AMyActor : public AActor
{
	GENERATED_BODY()


public:
	// Sets default values for this actor's properties
	AMyActor();
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnSomethingHappened OnSomethingHappened;

	void DoSomething();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};