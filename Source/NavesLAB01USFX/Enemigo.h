#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemigo.generated.h"

UCLASS()
class NAVESLAB01USFX_API AEnemigo : public AActor
{
    GENERATED_BODY()

public:
    AEnemigo();

	FVector DireccionMovimiento;
    FVector rango;

    // ===== COMPONENTES =====
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Colision")
    UStaticMeshComponent* MallaEnemigo;

    // ===== VIDA =====
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vida")
    float VidaMaxima = 100.0f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Vida")
    float VidaActual;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float Dano = 10.0f;

    // ===== MOVIMIENTO =====
    UPROPERTY()
    bool bMovimientoAutonomo = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento")
    float Velocidad = 200.0f;

    // ===== TIPO DE MOVIMIENTO PARA HIJAS =====
    UPROPERTY()
    int TipoMovimiento = 0;  // 0=recto, 1=zigzag, 2=circular, 3=senoide

    // ===== RUTA =====
    UPROPERTY()
    TArray<FVector> PuntosRuta;

    UPROPERTY()
    int32 IndicePuntoRutaActual = 0;

    UPROPERTY()
    FVector PosicionInicial = FVector::ZeroVector;

    UPROPERTY()
    float Tolerancia = 50.0f;

    // ===== ESCALADO (SOLO PARA EL PADRE/DONAS) =====
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Escalado")
    bool bCambiarEscala = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Escalado")
    float VelocidadEscala = 1.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Escalado")
    float EscalaMinima = 0.8f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Escalado")
    float EscalaMaxima = 1.2f;

    float EscalaActual = 1.0f;
    bool bAumentando = true;

    // ===== RODEAR NAVE (SOLO PARA EL PADRE/DONAS) =====
    UPROPERTY()
    bool bRodearNave = false;

    UPROPERTY()
    float RadioRodear = 350.0f;

    UPROPERTY()
    float VelocidadAngular = 120.0f;

    UPROPERTY()
    FVector CentroRodear = FVector::ZeroVector;

    UPROPERTY()
    float AnguloActual = 0.0f;
    bool bVivo;
    // ===== FUNCIONES PRINCIPALES =====
    virtual void Atacar(AActor* Objetivo);
    virtual void RecibirDanio(float Cantidad);
    virtual void ActualizarEfecto(float DeltaTime);
    virtual void Moverse(float DeltaTime);
    virtual void Disparar();
    virtual void CargarRuta();

    // ===== FUNCIONES DE ESCALADO Y RODEO =====
    virtual void CambiarEscala(float DeltaTime);
    virtual void ActivarRodearNave(FVector Centro, float NuevoRadio = 350.0f, float VelocidadNueva = 120.0f);
    virtual void DesactivarRodearNave();
    virtual void MoverRodearNave(float DeltaTime);

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

protected:
    UPROPERTY()
    class ANavesLAB01USFXPawn* Jugador = nullptr;

    UFUNCTION()
    virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Result);
};