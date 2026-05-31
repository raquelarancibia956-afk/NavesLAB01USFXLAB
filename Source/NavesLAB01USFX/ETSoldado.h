#pragma once

#include "CoreMinimal.h"
#include "EnemigoTerrestre.h"
#include "ETSoldado.generated.h"

UCLASS()
class NAVESLAB01USFX_API AETSoldado : public AEnemigoTerrestre
{
	GENERATED_BODY()

public:
	AETSoldado();
	virtual void Tick(float DeltaTime) override;
	virtual void CargarRuta() override;
};