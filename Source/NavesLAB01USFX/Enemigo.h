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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Colision")
	UStaticMeshComponent* MallaEnemigo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vida")
	float VidaMaxima = 100.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Vida")
	float VidaActual;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento")
	float Velocidad = 200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float Dano;
	UPROPERTY()
	FVector PosicionInicial;

	UPROPERTY()
	TArray<FVector> PuntosRuta;

	UPROPERTY()
	int32 IndicePuntoRutaActual = 0;

	UPROPERTY()
	float Tolerancia = 50.0f;

	// Funciones virtuales
	virtual void Atacar(AActor* Objetivo);
	virtual void RecibirDanio(float Cantidad);
	virtual void ActualizarEfecto(float DeltaTime);
	virtual void Moverse(float DeltaTime);
	virtual void Disparar();
	virtual void CargarRuta();  

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