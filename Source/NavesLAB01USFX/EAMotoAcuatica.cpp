#include "EAMotoAcuatica.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

AEAMotoAcuatica::AEAMotoAcuatica()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(
		TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'")
	);
	if (MallaAsset.Succeeded())
	{
		MallaEnemigo->SetStaticMesh(MallaAsset.Object);
	}

	Velocidad = 600.0f;
	VidaMaxima = 30.0f;
	VidaActual = VidaMaxima;
	Dano = 10.0f;
	SetActorScale3D(FVector(0.5f));
	TipoMovimiento = 1;
}

void AEAMotoAcuatica::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEAMotoAcuatica::CargarRuta()
{
	// Movimiento muy rápido y errático
	PosicionInicial = GetActorLocation();
	PuntosRuta.Empty();

	float Radio = 300.0f;
	int Puntos = 12;
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