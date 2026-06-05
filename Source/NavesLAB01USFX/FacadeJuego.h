#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FacadeJuego.generated.h"

class AEnemigo;

UCLASS()
class NAVESLAB01USFX_API AFacadeJuego : public AActor
{
	GENERATED_BODY()
	
public:	

	AFacadeJuego();
	void GenerarCuadrilla(int cantidad);
	TArray<AEnemigo*> Cuadrilla;
	UPROPERTY()
	TArray<TSubclassOf<AEnemigo>> ClasesEnemigos;
	void VerificarCuadrilla(float DeltaTime);
	int EnemigosVivos = 0;
protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
