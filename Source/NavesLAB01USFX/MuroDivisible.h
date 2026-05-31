#pragma once

#include "CoreMinimal.h"
#include "Muro.h"
#include "MuroDivisible.generated.h"

UCLASS()
class NAVESLAB01USFX_API AMuroDivisible : public AMuro
{
	GENERATED_BODY()

public:
	AMuroDivisible();

	virtual void RecibirDanio(float Cantidad) override;
	virtual void ActualizarEfecto(float DeltaTime) override;

private:
	int NumeroDivisiones;
	bool bYaDividido;
	void DividirMuro();
};