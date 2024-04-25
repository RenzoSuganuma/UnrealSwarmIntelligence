// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "SwarmManager.h"
#include "GameFramework/Actor.h"
#include "FlockMate.generated.h"

UCLASS()
class SWARMINTEL_API AFlockMate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlockMate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	TObjectPtr<ASwarmManager> GetSwarmManager();
	TObjectPtr<AActor> GetOtherMate();
	TObjectPtr<ASwarmManager> Manager;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
