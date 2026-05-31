#pragma once

#include "CoreMinimal.h"
#include "EnemigoTerrestre.h"
#include "ETBlindado.generated.h"

UCLASS()
class NAVESLAB01USFX_API AETBlindado : public AEnemigoTerrestre
{
	GENERATED_BODY()

public:
	AETBlindado();
	virtual void Tick(float DeltaTime) override;
	virtual void CargarRuta() override;
};