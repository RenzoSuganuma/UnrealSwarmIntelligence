// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SwarmMate.generated.h"

UCLASS()
class SWARMINTEL_API ASwarmMate : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	uint32 FlockSize;

	UPROPERTY(EditAnywhere)
	bool Debugging;

private:
	// 群れの個体
	TArray<TObjectPtr<AActor>> FlockMateArray;
	// 分離
	void Seperate();
	// 整列
	void Align();
	//	結束
	void Cohesive();

	//
	void SetupComponent();

public:
	// Sets default values for this actor's properties
	ASwarmMate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
