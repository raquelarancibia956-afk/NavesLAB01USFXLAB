#include "BloqueCamino.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

ABloqueCamino::ABloqueCamino()
{
    PrimaryActorTick.bCanEverTick = false;

    Malla = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Malla"));
    RootComponent = Malla;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(
        TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'")
    );
    if (MallaAsset.Succeeded())
    {
        Malla->SetStaticMesh(MallaAsset.Object);
    }

    PosicionX = 0;
    PosicionY = 0;
    bEsCamino = true;

    SetActorScale3D(FVector(1.0f, 1.0f, 0.2f));
}