#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "VRPawn.generated.h"

class UCameraComponent;
class UMotionControllerComponent;
class AGrabbableActor;

UCLASS()
class MYVRGAME_API AVRPawn : public APawn
{
    GENERATED_BODY()

public:
    AVRPawn();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UCameraComponent* VRCamera;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UMotionControllerComponent* LeftController;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UMotionControllerComponent* RightController;

    // Functions to grab and release objects
    void Grab();
    void Release();

    AGrabbableActor* HeldObject;
};

