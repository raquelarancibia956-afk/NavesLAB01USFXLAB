#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoTerrestre.generated.h"

UCLASS()
class NAVESLAB01USFX_API AEnemigoTerrestre : public AEnemigo
{
	GENERATED_BODY()

public:
	AEnemigoTerrestre();
	virtual void Tick(float DeltaTime) override;
	virtual void CargarRuta() override;
};