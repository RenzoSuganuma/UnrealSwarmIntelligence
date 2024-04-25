// Fill out your copyright notice in the Description page of Project Settings.


#include "FlockMate.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
AFlockMate::AFlockMate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

TObjectPtr<ASwarmManager> AFlockMate::GetSwarmManager()
{
	TSubclassOf<ASwarmManager> targetClass;
	targetClass = ASwarmManager::StaticClass();
	TArray<TObjectPtr<AActor>> managers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), targetClass, managers);

	if(managers.Num())
	{
		TObjectPtr<ASwarmManager> man = Cast<ASwarmManager>(managers[0]);
		return man;
	}
	else
	{
		return nullptr;
	}
}


// Called when the game starts or when spawned
void AFlockMate::BeginPlay()
{
	Super::BeginPlay();
	
	Manager = GetSwarmManager();
	Manager->JoinToFlock(this);
}

// Called every frame
void AFlockMate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector dir = FVector(Manager->GetActorLocation() - this->GetActorLocation());
	dir.Normalize();

	this->SetActorLocation(this->GetActorLocation() + dir);
}

