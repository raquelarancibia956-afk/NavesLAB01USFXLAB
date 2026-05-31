#include "EADron.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

AEADron::AEADron()
{
	PrimaryActorTick.bCanEverTick = true;

	Velocidad = 300.0f;
	VidaMaxima = 30.0f;
	VidaActual = VidaMaxima;
	Dano = 10.0f;
	SetActorScale3D(FVector(0.8f));  
	TipoMovimiento = 2;
}

void AEADron::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEADron::CargarRuta()
{
	// Movimiento circular pequeño
	PosicionInicial = GetActorLocation();
	PuntosRuta.Empty();

	float Radio = 200.0f;
	int Puntos = 20;
	float Z = PosicionInicial.Z;

	for (int i = 0; i <= Puntos; i++)
	{
		float Angulo = (360.0f / Puntos) * i;
		float Rad = FMath::DegreesToRadians(Angulo);
		float X = PosicionInicial.X + Radio * FMath::Cos(Rad);
		float Y = PosicionInicial.Y + Radio * FMath::Sin(Rad);
		PuntosRuta.Add(FVector(X, Y, Z));
	}

	IndicePuntoRutaActual = 0;
}