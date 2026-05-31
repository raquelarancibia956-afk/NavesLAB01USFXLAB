#include "ETTanque.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

AETTanque::AETTanque()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(
		TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'")
	);
	if (MallaAsset.Succeeded())
	{
		MallaEnemigo->SetStaticMesh(MallaAsset.Object);
	}

	Velocidad = 150.0f;
	VidaMaxima = 150.0f;
	VidaActual = VidaMaxima;
	Dano = 30.0f;
	SetActorScale3D(FVector(1.5f));
}

void AETTanque::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AETTanque::CargarRuta()
{
	// Movimiento lento en recta
	PosicionInicial = GetActorLocation();
	PuntosRuta.Empty();

	float Z = PosicionInicial.Z;

	PuntosRuta.Add(FVector(-1500, PosicionInicial.Y, Z));
	PuntosRuta.Add(FVector(1500, PosicionInicial.Y, Z));
	PuntosRuta.Add(FVector(-1500, PosicionInicial.Y, Z));

	IndicePuntoRutaActual = 0;
}