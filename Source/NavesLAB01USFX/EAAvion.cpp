#include "EAAvion.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

AEAAvion::AEAAvion()
{
	PrimaryActorTick.bCanEverTick = true;
	Velocidad = 500.0f;
	VidaMaxima = 40.0f;
	VidaActual = VidaMaxima;
	Dano = 20.0f;
	TipoMovimiento = 0;
}

void AEAAvion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEAAvion::CargarRuta()
{
	PosicionInicial = GetActorLocation();
	PuntosRuta.Empty();

	float Z = PosicionInicial.Z;

	PuntosRuta.Add(FVector(-2000, PosicionInicial.Y, Z));
	PuntosRuta.Add(FVector(2000, PosicionInicial.Y, Z));
	PuntosRuta.Add(FVector(-2000, PosicionInicial.Y, Z));

	IndicePuntoRutaActual = 0;
}