// Fill out your copyright notice in the Description page of Project Settings.
#include "SwarmManager.h"
#include "Kismet/KismetSystemLibrary.h"

void ASwarmManager::Seperate()
{
	if (isDebugging)
	{
		UKismetSystemLibrary::PrintString(this, TEXT("Seperate"), true, false, FColor::Orange);
	}
}

void ASwarmManager::Align()
{
	if (isDebugging)
	{
		UKismetSystemLibrary::PrintString(this, TEXT("Align"), true, false, FColor::Purple);
	}
}

void ASwarmManager::Cohesive()
{
	if (isDebugging)
	{
		UKismetSystemLibrary::PrintString(this, TEXT("Cohesive"), true, false, FColor::Turquoise);
	}
}

void ASwarmManager::SetupComponent()
{
	if (isDebugging)
	{
		UKismetSystemLibrary::PrintString(this, TEXT("SetUpHere"), true, false, FColor::Magenta);
	}
}

// Sets default values
ASwarmManager::ASwarmManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ASwarmManager::JoinToFlock(TObjectPtr<AActor> actor)
{
	if (!FlockMateArray.Contains(actor))
	{
		FlockMateArray.Add(actor);
	}
}

TArray<TObjectPtr<AActor>> ASwarmManager::GetFlockMates()
{
	return  this->FlockMateArray;
}

// Called when the game starts or when spawned
void ASwarmManager::BeginPlay()
{
	Super::BeginPlay();
	
	SetupComponent();
}

// Called every frame
void ASwarmManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	int32 len = FlockMateArray.Num();
	FString message = FString::FromInt(len).Append("= Length");
	UKismetSystemLibrary::PrintString(this, message, 1, 0, FColor::Purple);
	Seperate();
	Align();
	Cohesive();
}
