#pragma once

#include "CoreMinimal.h"
#include "EnemigoAereo.h"
#include "EAAvion.generated.h"

UCLASS()
class NAVESLAB01USFX_API AEAAvion : public AEnemigoAereo
{
	GENERATED_BODY()

public:
	AEAAvion();
	virtual void Tick(float DeltaTime) override;
	virtual void CargarRuta() override;
};