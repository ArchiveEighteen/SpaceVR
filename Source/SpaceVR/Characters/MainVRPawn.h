// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "GameFramework/Pawn.h"
#include "MainVRPawn.generated.h"

UCLASS()
class SPACEVR_API AMainVRPawn : public APawn
{
	GENERATED_BODY()

public:
	AMainVRPawn();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=Input)
	UInputAction* TurnInputAction;
	
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
protected:
	// ----- Input Delegates -----
	void Turn(const FInputActionInstance& Instance);
	
	// ----- Helper Functions -----
	void SnapTurn(bool rightTurn);
};
