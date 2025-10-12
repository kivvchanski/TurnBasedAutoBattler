// Fill out your copyright notice in the Description page of Project Settings.



#include "Listener.h"

// Sets default values
AListener::AListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AListener::BeginPlay()
{
	Super::BeginPlay();
	if (ObservedActor) {
		ObservedActor->OnSomethingHappened.AddDynamic(this, &AListener::HandleSomethingHappened);

	}
}

// Called every frame
void AListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AListener::HandleSomethingHappened()
{
	UE_LOG(LogTemp, Warning, TEXT("ListenerActor received the event!"));
}
