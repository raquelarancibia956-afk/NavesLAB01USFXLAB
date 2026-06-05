#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BloqueCamino.generated.h"

UCLASS()
class NAVESLAB01USFX_API ABloqueCamino : public AActor
{
    GENERATED_BODY()

public:
    ABloqueCamino();

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* Malla;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int PosicionX;  // Posicion en la cuadricula X

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int PosicionY;  // Posicion en la cuadricula Y

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bEsCamino;  // true = camino, false = obstaculo
};