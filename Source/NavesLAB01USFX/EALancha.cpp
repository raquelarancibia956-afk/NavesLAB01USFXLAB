#include "EALancha.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

AEALancha::AEALancha()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(
		TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'")
	);
	if (MallaAsset.Succeeded())
	{
		MallaEnemigo->SetStaticMesh(MallaAsset.Object);
	}

	Velocidad = 450.0f;
	VidaMaxima = 50.0f;
	VidaActual = VidaMaxima;
	Dano = 15.0f;
	SetActorScale3D(FVector(0.7f));
}

void AEALancha::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEALancha::CargarRuta()
{
	// Movimiento rápido en zigzag
	PosicionInicial = GetActorLocation();
	PuntosRuta.Empty();

	float Z = PosicionInicial.Z;

	for (int i = 0; i <= 30; i++)
	{
		float X = PosicionInicial.X + (i * 100.0f);
		float Y = PosicionInicial.Y + (i % 2 == 0 ? 200.0f : -200.0f);
		PuntosRuta.Add(FVector(X, Y, Z));
	}

	IndicePuntoRutaActual = 0;
}