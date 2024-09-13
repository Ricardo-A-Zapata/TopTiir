#include "GrabbableActor.h"
#include "Components/StaticMeshComponent.h"

AGrabbableActor::AGrabbableActor()
{
    PrimaryActorTick.bCanEverTick = true;

    // Create and initialize the mesh component
    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    RootComponent = Mesh;

    // Enable physics for the mesh to allow grabbing
    Mesh->SetSimulatePhysics(true);
}

void AGrabbableActor::BeginPlay()
{
    Super::BeginPlay();
}

void AGrabbableActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AGrabbableActor::Grab()
{
    Mesh->SetSimulatePhysics(false);  // Disable physics when grabbed
}

void AGrabbableActor::Release()
{
    Mesh->SetSimulatePhysics(true);   // Enable physics on release
}

