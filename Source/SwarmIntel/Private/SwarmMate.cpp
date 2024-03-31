// Fill out your copyright notice in the Description page of Project Settings.


#include "SwarmMate.h"

#include "Kismet/KismetSystemLibrary.h"

void ASwarmMate::Seperate()
{
	if(Debugging)
	{
		UKismetSystemLibrary::PrintString(this, TEXT("Seperate"), true, false, FColor::Orange);
	}
}

void ASwarmMate::Align()
{
	if(Debugging)
	{
		UKismetSystemLibrary::PrintString(this, TEXT("Align"), true, false, FColor::Purple);
	}
}

void ASwarmMate::Cohesive()
{
	if(Debugging)
	{
		UKismetSystemLibrary::PrintString(this, TEXT("Cohesive"), true, false, FColor::Turquoise);
	}
}

void ASwarmMate::SetupComponent()
{
	UKismetSystemLibrary::PrintString(this, TEXT("SetUpHere"), true, false, FColor::Magenta);
}

// Sets default values
ASwarmMate::ASwarmMate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASwarmMate::BeginPlay()
{
	SetupComponent();
}

// Called every frame
void ASwarmMate::Tick(float DeltaTime)
{
	Seperate();
	Align();
	Cohesive();
}

