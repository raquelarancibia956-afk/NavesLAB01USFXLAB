#pragma once

#include "CoreMinimal.h"
#include "EnemigoAereo.h"
#include "EADron.generated.h"

UCLASS()
class NAVESLAB01USFX_API AEADron : public AEnemigoAereo
{
	GENERATED_BODY()

public:
	AEADron();
	virtual void Tick(float DeltaTime) override;
	virtual void CargarRuta() override;
};