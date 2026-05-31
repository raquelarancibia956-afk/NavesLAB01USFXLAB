#include "ETBlindado.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

AETBlindado::AETBlindado()
{
	Velocidad = 120.0f;
	VidaMaxima = 200.0f;
	VidaActual = VidaMaxima;
	Dano = 25.0f;
	SetActorScale3D(FVector(1.3f));
	TipoMovimiento = 2;
}

void AETBlindado::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AETBlindado::CargarRuta()
{
	// Movimiento defensivo (pequeño círculo)
	PosicionInicial = GetActorLocation();
	PuntosRuta.Empty();

	float Radio = 150.0f;
	int Puntos = 16;
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