#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoAereo.generated.h"

UCLASS()
class NAVESLAB01USFX_API AEnemigoAereo : public AEnemigo
{
	GENERATED_BODY()

public:
	AEnemigoAereo();
	virtual void Tick(float DeltaTime) override;
	virtual void CargarRuta() override;
};