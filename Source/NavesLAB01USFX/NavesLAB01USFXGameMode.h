#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NavesLAB01USFXGameMode.generated.h"

class AEnemigo;
class APawn;
class AMuro;
class ABloqueCamino;
class AFacadeJuego;

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

    // ===== LISTA DE DONAS (PADRE) =====
    UPROPERTY()
    TArray<AEnemigo*> ListaEnemigos;

    // ===== CONTENEDOR DE 20 NAVES (HIJAS) =====
    UPROPERTY()
    TArray<AEnemigo*> ContenedorNaves;

    bool bEnFormacion;
    FTimerHandle TimerCambioModo;

    // ===== CUADRILLAS =====
 
    UPROPERTY()
    AFacadeJuego* FacadeJuego;

   // UPROPERTY()
   // TArray<AEnemigo*> Cuadrilla2;

    UPROPERTY()
    ECuadrilla CuadrillaActual;

    FTimerHandle TimerRevisarCuadrilla;

    // ===== MUROS =====
    UPROPERTY()
    TArray<AMuro*> MurosArray;

    // ===== BLOQUES DE CAMINO =====
    UPROPERTY()
    TArray<ABloqueCamino*> ListaBloques;

 

    // ===== MÉTODOS =====
    void GenerarContenedorNaves();
    /*void GenerarCuadrilla1();
    void GenerarCuadrilla2();
    void RevisarCuadrilla();*/
    void FormarNaves();
    void ModoAutonomo();
    void CambiarModo();
    void GenerarMuros();
    void GenerarCamino();

    void CrearMuroDeslizante(UWorld* World, FVector Posicion, FVector Direccion, float Distancia, float Velocidad);
    void CrearMuroParpadeante(UWorld* World, FVector Posicion, float TiempoVisible, float TiempoInvisible);
    void CrearMuroDivisible(UWorld* World, FVector Posicion);
    void CrearMuroEstatico(UWorld* World, FVector Posicion, FVector Dimension);

    APawn* PlayerPawn;
    float EspaciadoFormacion = 100.0f;
};