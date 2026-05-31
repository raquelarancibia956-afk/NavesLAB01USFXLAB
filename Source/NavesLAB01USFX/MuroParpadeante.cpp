#include "MuroParpadeante.h"

AMuroParpadeante::AMuroParpadeante()
{
	PrimaryActorTick.bCanEverTick = true;

	TiempoVisible = 2.0f;
	TiempoInvisible = 1.0f;
	TiempoActual = 0.0f;
	bVisible = true;

	Dimension = FVector(4.0f, 1.0f, 1.0f);
	ActualizarEscala();
}

void AMuroParpadeante::ActualizarEfecto(float DeltaTime)
{
	TiempoActual += DeltaTime;

	if (bVisible && TiempoActual >= TiempoVisible)
	{
		bVisible = false;
		TiempoActual = 0.0f;
		SetActorHiddenInGame(true);
		SetActorEnableCollision(false);
	}
	else if (!bVisible && TiempoActual >= TiempoInvisible)
	{
		bVisible = true;
		TiempoActual = 0.0f;
		SetActorHiddenInGame(false);
		SetActorEnableCollision(true);
	}
}