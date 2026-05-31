#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoAcuatico.generated.h"

UCLASS()
class NAVESLAB01USFX_API AEnemigoAcuatico : public AEnemigo
{
	GENERATED_BODY()

public:
	AEnemigoAcuatico();
	virtual void Tick(float DeltaTime) override;
	virtual void CargarRuta() override;
};