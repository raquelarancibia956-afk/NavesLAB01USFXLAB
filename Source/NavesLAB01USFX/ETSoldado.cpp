#include "ETSoldado.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

AETSoldado::AETSoldado()
{
	Velocidad = 300.0f;
	VidaMaxima = 40.0f;
	VidaActual = VidaMaxima;
	Dano = 15.0f;
	SetActorScale3D(FVector(0.6f));
	TipoMovimiento = 0;
}

void AETSoldado::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AETSoldado::CargarRuta()
{
	// Movimiento errático
	PosicionInicial = GetActorLocation();
	PuntosRuta.Empty();

	float Z = PosicionInicial.Z;

	for (int i = 0; i <= 20; i++)
	{
		float X = PosicionInicial.X + (i * 80.0f);
		float Y = PosicionInicial.Y + FMath::Sin(i) * 150.0f;
		PuntosRuta.Add(FVector(X, Y, Z));
	}

	IndicePuntoRutaActual = 0;
}