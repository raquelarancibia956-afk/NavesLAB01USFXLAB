// NavesLAB01USFXGameMode.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NavesLAB01USFXGameMode.generated.h"

class AEnemigo;
class APawn;
class AMuro;

UENUM(BlueprintType)
enum class ECuadrilla : uint8
{
    Primera,
    Segunda
};

UCLASS(MinimalAPI)
class ANavesLAB01USFXGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    ANavesLAB01USFXGameMode();

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    UPROPERTY()
    TArray<AEnemigo*> Cuadrilla1;

    UPROPERTY()
    TArray<AEnemigo*> Cuadrilla2;

    UPROPERTY()
    TArray<AMuro*> MurosArray;

    UPROPERTY()
    ECuadrilla CuadrillaActual;

    FTimerHandle TimerRevisarCuadrilla;

    void GenerarCuadrilla1();
    void GenerarCuadrilla2();
    void RevisarCuadrilla();
    void LimpiarCuadrillas();

    void GenerarMuros();
    void CrearMuroDeslizante(UWorld* World, FVector Posicion, FVector Direccion, float Distancia, float Velocidad);
    void CrearMuroParpadeante(UWorld* World, FVector Posicion, float TiempoVisible, float TiempoInvisible);
    void CrearMuroDivisible(UWorld* World, FVector Posicion);
    void CrearMuroEstatico(UWorld* World, FVector Posicion, FVector Dimension);

    APawn* PlayerPawn;
};