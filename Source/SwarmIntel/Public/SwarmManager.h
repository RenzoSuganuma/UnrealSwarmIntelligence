// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SwarmManager.generated.h"

UCLASS()
class SWARMINTEL_API ASwarmManager : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	uint32 uiFlockSize;

	UPROPERTY(EditAnywhere)
	bool isDebugging;

private:
	// 群れの個体
	TArray<TObjectPtr<AActor>> FlockMateArray;
	// 分離
	void Seperate();
	// 整列
	void Align();
	//	結束
	void Cohesive();
	// 群れのセットアップ
	void SetupComponent();

public:
	// Sets default values for this actor's properties
	ASwarmManager();
	// 群れに登録
	void JoinToFlock(TObjectPtr<AActor> actor);
	TArray<TObjectPtr<AActor>> GetFlockMates();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
