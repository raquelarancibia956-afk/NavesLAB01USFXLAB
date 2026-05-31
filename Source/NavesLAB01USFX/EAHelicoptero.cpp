#include "EAHelicoptero.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

AEAHelicoptero::AEAHelicoptero()
{
	PrimaryActorTick.bCanEverTick = true;  
	Velocidad = 400.0f;
	VidaMaxima = 50.0f;
	VidaActual = VidaMaxima;
	Dano = 25.0f;
	TipoMovimiento = 3;
}

void AEAHelicoptero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEAHelicoptero::CargarRuta()
{
	// Movimiento en zigzag
	PosicionInicial = GetActorLocation();
	PuntosRuta.Empty();

	float Ancho = 400.0f;
	float Largo = 800.0f;
	float Z = PosicionInicial.Z;

	for (int i = 0; i <= 10; i++)
	{
		float X = PosicionInicial.X + (i * 100.0f);
		float Y = PosicionInicial.Y + (i % 2 == 0 ? Ancho : -Ancho);
		PuntosRuta.Add(FVector(X, Y, Z));
	}

	IndicePuntoRutaActual = 0;
}