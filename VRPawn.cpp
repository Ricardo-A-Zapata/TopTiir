#include "VRPawn.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "MotionControllerComponent.h"
#include "GrabbableActor.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

AVRPawn::AVRPawn()
{
    PrimaryActorTick.bCanEverTick = true;

    // Initialize the camera component
    VRCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("VRCamera"));
    RootComponent = VRCamera;

    // Initialize motion controller components
    LeftController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("LeftController"));
    LeftController->SetupAttachment(RootComponent);
    LeftController->SetTrackingSource(EControllerHand::Left);

    RightController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("RightController"));
    RightController->SetupAttachment(RootComponent);
    RightController->SetTrackingSource(EControllerHand::Right);
}

void AVRPawn::BeginPlay()
{
    Super::BeginPlay();
}

void AVRPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AVRPawn::Grab()
{
    // Line trace from the right controller to detect grabbable objects
    FVector Start = RightController->GetComponentLocation();
    FVector End = Start + (RightController->GetForwardVector() * 200.0f);

    FHitResult HitResult;
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(this);

    bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, Params);

    if (bHit && HitResult.Actor.IsValid())
    {
        AGrabbableActor* Grabbable = Cast<AGrabbableActor>(HitResult.Actor);
        if (Grabbable)
        {
            Grabbable->Grab();
            HeldObject = Grabbable;
        }
    }
}

void AVRPawn::Release()
{
    if (HeldObject)
    {
        HeldObject->Release();
        HeldObject = nullptr;
    }
}

