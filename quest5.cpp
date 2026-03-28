// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Engine/Engine.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(0.f, 50.f, 0.f)); //시작위치 고정

	for (int i = 0; i < 10; i++) // 10회 무작위
	{
		Move(FMath::RandRange(50.f, 200.f));
		Turn(FMath::RandRange(-90.f, 90.f));
	}
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::Move(float Distance) // move
{
	FVector NewLocation = GetActorLocation() + FVector(Distance, 0.f, 0.f);
	SetActorLocation(NewLocation);

	if (GEngine) {
		FVector CurrentLocation = GetActorLocation();

		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::White, FString::Printf(TEXT("X: %.1f Y: %.1f Z: %.1f"), CurrentLocation.X, CurrentLocation.Y, CurrentLocation.Z));
		//반복, duration, color, print...
	}
}

void AMyActor::Turn(float Angle) //angle
{
    FRotator NewRotation = GetActorRotation() + FRotator(0.f, Angle, 0.f);
    SetActorRotation(NewRotation);
}
