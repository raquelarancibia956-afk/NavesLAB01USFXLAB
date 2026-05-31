#pragma once

#include "CoreMinimal.h"
#include "Muro.h"
#include "MuroDeslizante.generated.h"

UCLASS()
class NAVESLAB01USFX_API AMuroDeslizante : public AMuro
{
	GENERATED_BODY()

public:
	AMuroDeslizante();

	virtual void ActualizarEfecto(float DeltaTime) override;
	virtual void BeginPlay() override;

private:
	FVector Direccion;
	float DistanciaMaxima;
	float Velocidad;
	FVector PosicionInicial;
	FVector PosicionDestino;
	bool bAdelante;
};