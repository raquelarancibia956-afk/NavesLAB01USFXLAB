// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NavesLAB01USFXGameMode.generated.h"

class AEnemigo;
class APawn;
class AMuro;
class AMuroDeslizante;
class AMuroParpadeante;
class AMuroDivisible;
class AMuroEstatico;

UCLASS(MinimalAPI)
class ANavesLAB01USFXGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ANavesLAB01USFXGameMode();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// ===== CONTENEDORES PARA ALMACENAR OBJETOS =====
	UPROPERTY()
	TArray<AEnemigo*> AEnemigos;

	UPROPERTY()
	TArray<AMuro*> MurosArray;

	// ===== MÉTODOS DE ENEMIGOS =====
	void GenerarEnemigos();

	// ===== MÉTODOS DE MUROS =====
	void GenerarMuros();
	void CrearMuroDeslizante(UWorld* World, FVector Posicion, FVector Direccion, float Distancia, float Velocidad);
	void CrearMuroParpadeante(UWorld* World, FVector Posicion, float TiempoVisible, float TiempoInvisible);
	void CrearMuroDivisible(UWorld* World, FVector Posicion);
	void CrearMuroEstatico(UWorld* World, FVector Posicion, FVector Dimension);

	APawn* PlayerPawn;
};