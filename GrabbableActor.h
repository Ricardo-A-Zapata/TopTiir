#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GrabbableActor.generated.h"

UCLASS()
class MYVRGAME_API AGrabbableActor : public AActor
{
    GENERATED_BODY()

public:    
    // Sets default values for this actor's properties
    AGrabbableActor();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:    
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Mesh component for the grabbable object
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grabbable")
    UStaticMeshComponent* Mesh;

    // Functions to grab and release the object
    void Grab();
    void Release();
};

