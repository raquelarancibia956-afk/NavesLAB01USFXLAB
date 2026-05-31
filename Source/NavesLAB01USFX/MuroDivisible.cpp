#include "MuroDivisible.h"

AMuroDivisible::AMuroDivisible()
{
	PrimaryActorTick.bCanEverTick = true;

	NumeroDivisiones = 4;
	bYaDividido = false;
	Resistencia = 50.0f;

	Dimension = FVector(8.0f, 1.0f, 2.0f);
	ActualizarEscala();
}

void AMuroDivisible::RecibirDanio(float Cantidad)
{
	Resistencia -= Cantidad;
	if (Resistencia <= 0.0f && !bYaDividido)
	{
		DividirMuro();
	}
}

void AMuroDivisible::ActualizarEfecto(float DeltaTime)
{
	// Vacío - solo necesita el tick activado
}

void AMuroDivisible::DividirMuro()
{
	bYaDividido = true;
	Destroy();
}