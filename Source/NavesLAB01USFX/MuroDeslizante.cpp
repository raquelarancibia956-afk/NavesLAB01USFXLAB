#include "MuroDeslizante.h"

AMuroDeslizante::AMuroDeslizante()
{
	PrimaryActorTick.bCanEverTick = true;

	Direccion = FVector(1.0f, 0.0f, 0.0f);
	DistanciaMaxima = 300.0f;
	Velocidad = 150.0f;
	bAdelante = true;

	Dimension = FVector(2.0f, 1.0f, 2.0f);
	ActualizarEscala();
}

void AMuroDeslizante::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation();
	PosicionDestino = PosicionInicial + (Direccion.GetSafeNormal() * DistanciaMaxima);
}

void AMuroDeslizante::ActualizarEfecto(float DeltaTime)
{
	FVector NuevaPos = GetActorLocation();

	if (bAdelante)
	{
		NuevaPos += Direccion.GetSafeNormal() * Velocidad * DeltaTime;
		if (FVector::Dist(NuevaPos, PosicionDestino) <= 10.0f)
		{
			NuevaPos = PosicionDestino;
			bAdelante = false;
		}
	}
	else
	{
		NuevaPos -= Direccion.GetSafeNormal() * Velocidad * DeltaTime;
		if (FVector::Dist(NuevaPos, PosicionInicial) <= 10.0f)
		{
			NuevaPos = PosicionInicial;
			bAdelante = true;
		}
	}

	SetActorLocation(NuevaPos);
}