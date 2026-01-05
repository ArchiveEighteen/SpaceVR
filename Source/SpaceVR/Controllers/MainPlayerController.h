// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SPACEVR_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=Input)
	TSoftObjectPtr<UInputMappingContext> InputMappingDefault;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=Input)
	TSoftObjectPtr<UInputMappingContext> InputMappingHands;
	
	virtual void BeginPlay() override;
};
