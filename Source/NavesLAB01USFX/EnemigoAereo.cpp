#include "EnemigoAereo.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

AEnemigoAereo::AEnemigoAereo()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(
		TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_TriPyramid.Shape_TriPyramid'")
	);
	if (MallaAsset.Succeeded())
	{
		MallaEnemigo->SetStaticMesh(MallaAsset.Object);
	}

	Velocidad = 350.0f;
	VidaMaxima = 60.0f;
	VidaActual = VidaMaxima;
	Dano = 20.0f;
}

void AEnemigoAereo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemigoAereo::CargarRuta()
{
	PosicionInicial = GetActorLocation();
	PuntosRuta.Empty();

	float Radio = 500.0f;
	int Puntos = 36;
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