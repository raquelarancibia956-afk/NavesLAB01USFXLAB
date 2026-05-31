#include "EnemigoAcuatico.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

AEnemigoAcuatico::AEnemigoAcuatico()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(
		TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'")
	);
	if (MallaAsset.Succeeded())
	{
		MallaEnemigo->SetStaticMesh(MallaAsset.Object);
	}

	Velocidad = 300.0f;
	VidaMaxima = 80.0f;
	VidaActual = VidaMaxima;
	Dano = 15.0f;
}

void AEnemigoAcuatico::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemigoAcuatico::CargarRuta()
{
	PosicionInicial = GetActorLocation();
	PuntosRuta.Empty();

	float LimiteDerecha = 2000.0f;
	float LimiteIzquierda = -2000.0f;
	float Z = PosicionInicial.Z;

	// Ida
	for (float X = LimiteIzquierda; X <= LimiteDerecha; X += 100.0f)
	{
		PuntosRuta.Add(FVector(X, PosicionInicial.Y, Z));
	}
	// Vuelta
	for (float X = LimiteDerecha; X >= LimiteIzquierda; X -= 100.0f)
	{
		PuntosRuta.Add(FVector(X, PosicionInicial.Y, Z));
	}

	IndicePuntoRutaActual = 0;
}