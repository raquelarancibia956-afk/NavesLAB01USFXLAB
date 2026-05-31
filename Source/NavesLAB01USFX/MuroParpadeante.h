#pragma once

#include "CoreMinimal.h"
#include "Muro.h"
#include "MuroParpadeante.generated.h"

UCLASS()
class NAVESLAB01USFX_API AMuroParpadeante : public AMuro
{
	GENERATED_BODY()

public:
	AMuroParpadeante();

	virtual void ActualizarEfecto(float DeltaTime) override;

private:
	float TiempoVisible;
	float TiempoInvisible;
	float TiempoActual;
	bool bVisible;
};