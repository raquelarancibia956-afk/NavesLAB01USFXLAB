#include "MuroEstatico.h"

AMuroEstatico::AMuroEstatico()
{
	PrimaryActorTick.bCanEverTick = false;

	Dimension = FVector(3.0f, 1.0f, 2.0f);
	ActualizarEscala();
}