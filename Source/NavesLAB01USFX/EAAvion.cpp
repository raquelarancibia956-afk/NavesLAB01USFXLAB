#include "EAAvion.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

AEAAvion::AEAAvion()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(
		TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_TriPyramid.Shape_TriPyramid'")
	);
	if (MallaAsset.Succeeded())
	{
		MallaEnemigo->SetStaticMesh(MallaAsset.Object);
	}

	Velocidad = 500.0f;
	VidaMaxima = 40.0f;
	VidaActual = VidaMaxima;
	Dano = 20.0f;
}

void AEAAvion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEAAvion::CargarRuta()
{
	// Movimiento recto rápido
	PosicionInicial = GetActorLocation();
	PuntosRuta.Empty();

	float Z = PosicionInicial.Z;

	PuntosRuta.Add(FVector(-2000, PosicionInicial.Y, Z));
	PuntosRuta.Add(FVector(2000, PosicionInicial.Y, Z));
	PuntosRuta.Add(FVector(-2000, PosicionInicial.Y, Z));

	IndicePuntoRutaActual = 0;
}