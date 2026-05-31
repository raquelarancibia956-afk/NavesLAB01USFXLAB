#pragma once

#include "CoreMinimal.h"
#include "EnemigoAereo.h"
#include "EAHelicoptero.generated.h"

UCLASS()
class NAVESLAB01USFX_API AEAHelicoptero : public AEnemigoAereo
{
	GENERATED_BODY()

public:
	AEAHelicoptero();
	virtual void Tick(float DeltaTime) override;
	virtual void CargarRuta() override;
};