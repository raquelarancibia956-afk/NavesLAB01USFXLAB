#include "ETCamion.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

AETCamion::AETCamion()
{
	Velocidad = 200.0f;
	VidaMaxima = 80.0f;
	VidaActual = VidaMaxima;
	Dano = 12.0f;
	SetActorScale3D(FVector(1.2f, 1.8f, 1.0f));
	TipoMovimiento = 3;
}

void AETCamion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AETCamion::CargarRuta()
{
	// Movimiento en cuadrado
	PosicionInicial = GetActorLocation();
	PuntosRuta.Empty();

	float Tamano = 500.0f;
	float Z = PosicionInicial.Z;

	PuntosRuta.Add(FVector(PosicionInicial.X - Tamano, PosicionInicial.Y - Tamano, Z));
	PuntosRuta.Add(FVector(PosicionInicial.X + Tamano, PosicionInicial.Y - Tamano, Z));
	PuntosRuta.Add(FVector(PosicionInicial.X + Tamano, PosicionInicial.Y + Tamano, Z));
	PuntosRuta.Add(FVector(PosicionInicial.X - Tamano, PosicionInicial.Y + Tamano, Z));
	PuntosRuta.Add(FVector(PosicionInicial.X - Tamano, PosicionInicial.Y - Tamano, Z));

	IndicePuntoRutaActual = 0;
}