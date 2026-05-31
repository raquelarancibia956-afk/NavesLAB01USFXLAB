#pragma once

#include "CoreMinimal.h"
#include "EnemigoAcuatico.h"
#include "EAMotoAcuatica.generated.h"

UCLASS()
class NAVESLAB01USFX_API AEAMotoAcuatica : public AEnemigoAcuatico
{
	GENERATED_BODY()

public:
	AEAMotoAcuatica();
	virtual void Tick(float DeltaTime) override;
	virtual void CargarRuta() override;
};