#include "EABarco.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

AEABarco::AEABarco()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(
		TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'")
	);
	if (MallaAsset.Succeeded())
	{
		MallaEnemigo->SetStaticMesh(MallaAsset.Object);
	}

	Velocidad = 200.0f;
	VidaMaxima = 120.0f;
	VidaActual = VidaMaxima;
	Dano = 25.0f;
	SetActorScale3D(FVector(1.8f));
	TipoMovimiento = 1;
}

void AEABarco::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEABarco::CargarRuta()
{
	// Movimiento lento horizontal
	PosicionInicial = GetActorLocation();
	PuntosRuta.Empty();

	float Z = PosicionInicial.Z;

	PuntosRuta.Add(FVector(-1800, PosicionInicial.Y, Z));
	PuntosRuta.Add(FVector(1800, PosicionInicial.Y, Z));
	PuntosRuta.Add(FVector(-1800, PosicionInicial.Y, Z));

	IndicePuntoRutaActual = 0;
}