// Fill out your copyright notice in the Description page of Project Settings.


#include "MainVRPawn.h"

#include "EnhancedInputComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "XRLoadingScreenFunctionLibrary.h"
#include "Kismet/KismetSystemLibrary.h"


AMainVRPawn::AMainVRPawn()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMainVRPawn::BeginPlay()
{
	Super::BeginPlay();
	
	if (!UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled()) return;
	
	UHeadMountedDisplayFunctionLibrary::SetTrackingOrigin(EHMDTrackingOrigin::LocalFloor);
	
	// The xr.SecondaryScreenPercentage.HMDRenderTarget will under or over-sample the resolution for your Head Mounted Display.
	// See "https://portal.productboard.com/epicgames/1-unreal-engine-public-roadmap/c/1725-xr-resolution-scaling" for more details
	UKismetSystemLibrary::ExecuteConsoleCommand(this, TEXT("xr.SecondaryScreenPercentage.HMDRenderTarget 100"));
	
	UXRLoadingScreenFunctionLibrary::HideLoadingScreen();
}

void AMainVRPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMainVRPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
}