#pragma once

#include "CoreMinimal.h"
#include "EnemigoTerrestre.h"
#include "ETTanque.generated.h"

UCLASS()
class NAVESLAB01USFX_API AETTanque : public AEnemigoTerrestre
{
	GENERATED_BODY()

public:
	AETTanque();
	virtual void Tick(float DeltaTime) override;
	virtual void CargarRuta() override;
};