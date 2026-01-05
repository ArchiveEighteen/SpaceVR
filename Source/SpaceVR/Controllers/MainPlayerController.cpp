// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerController.h"
#include "EnhancedInputSubsystems.h"


void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (const ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player))
	{
		if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (!InputMappingDefault.IsNull())
			{
				InputSystem->AddMappingContext(InputMappingDefault.LoadSynchronous(), 0);
			}
			
			if (!InputMappingHands.IsNull())
			{
				InputSystem->AddMappingContext(InputMappingHands.LoadSynchronous(), 0);
			}
		}
	}
}
