#pragma once

#include "CoreMinimal.h"
#include "EnemigoAcuatico.h"
#include "EALancha.generated.h"

UCLASS()
class NAVESLAB01USFX_API AEALancha : public AEnemigoAcuatico
{
	GENERATED_BODY()

public:
	AEALancha();
	virtual void Tick(float DeltaTime) override;
	virtual void CargarRuta() override;
};