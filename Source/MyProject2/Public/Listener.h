// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <MyActor.h>
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Listener.generated.h"


UCLASS()
class MYPROJECT2_API AListener : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AListener();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION()
	void HandleSomethingHappened();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "References")
	AMyActor* ObservedActor;
};
