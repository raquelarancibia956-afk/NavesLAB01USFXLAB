#pragma once

#include "CoreMinimal.h"
#include "EnemigoAcuatico.h"
#include "EABarco.generated.h"

UCLASS()
class NAVESLAB01USFX_API AEABarco : public AEnemigoAcuatico
{
	GENERATED_BODY()

public:
	AEABarco();
	virtual void Tick(float DeltaTime) override;
	virtual void CargarRuta() override;
};