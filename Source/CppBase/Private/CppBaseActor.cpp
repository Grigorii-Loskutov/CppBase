// Fill out your copyright notice in the Description page of Project Settings.

#include "CppBaseActor.h"
#include "TimerManager.h"

// Sets default values
ACppBaseActor::ACppBaseActor() {
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}

ACppBaseActor::ACppBaseActor(bool IsAlive, int EnemyNum, FString ActorName)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->IsAlive = IsAlive;
	this->EnemyNum = EnemyNum;
	this->ActorName = ActorName;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	// Вызываем BeginPlay, чтобы значения из редактора были применены
	Super::BeginPlay();

}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();


	//ShowInformation();
	ShowActorInformation();
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACppBaseActor::ShowInformation() {
	//Пример из лекции
	
	UE_LOG(LogTemp, Warning, TEXT("ShowInformation print"));
	/*
	UE_LOG(LogTemp, Warning, TEXT("CppBase is failed"));
	UE_LOG(LogTemp, Error, TEXT("CppBase is crached!"));

	int EnemyNum = 20;
	float CurrentHealth = 57.54687;
	bool IsAlive = true;

	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("CurrentHealth: %f"), CurrentHealth);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), IsAlive);
	*/
}

void ACppBaseActor::ShowActorInformation() {
	UE_LOG(LogTemp, Display, TEXT("ObjName: %s"), *ActorName);
	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), IsAlive);
}
