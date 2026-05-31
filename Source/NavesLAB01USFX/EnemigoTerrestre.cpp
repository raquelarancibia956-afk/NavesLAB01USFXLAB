#include "EnemigoTerrestre.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

AEnemigoTerrestre::AEnemigoTerrestre()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(
		TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'")
	);
	if (MallaAsset.Succeeded())
	{
		MallaEnemigo->SetStaticMesh(MallaAsset.Object);
	}

	Velocidad = 250.0f;
	VidaMaxima = 100.0f;
	VidaActual = VidaMaxima;
	Dano = 10.0f;
}

void AEnemigoTerrestre::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemigoTerrestre::CargarRuta()
{
	PosicionInicial = GetActorLocation();
	PuntosRuta.Empty();

	float Tamano = 600.0f;
	float Z = PosicionInicial.Z;

	PuntosRuta.Add(FVector(PosicionInicial.X - Tamano, PosicionInicial.Y - Tamano, Z));
	PuntosRuta.Add(FVector(PosicionInicial.X + Tamano, PosicionInicial.Y - Tamano, Z));
	PuntosRuta.Add(FVector(PosicionInicial.X + Tamano, PosicionInicial.Y + Tamano, Z));
	PuntosRuta.Add(FVector(PosicionInicial.X - Tamano, PosicionInicial.Y + Tamano, Z));
	PuntosRuta.Add(FVector(PosicionInicial.X - Tamano, PosicionInicial.Y - Tamano, Z));

	IndicePuntoRutaActual = 0;
}