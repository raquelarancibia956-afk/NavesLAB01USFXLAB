// Copyright Epic Games, Inc. All Rights Reserved.

#include "NavesLAB01USFXGameMode.h"
#include "NavesLAB01USFXPawn.h"
#include "Enemigo.h"
#include "Muro.h"
#include "MuroDeslizante.h"
#include "MuroParpadeante.h"
#include "MuroDivisible.h"
#include "MuroEstatico.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

ANavesLAB01USFXGameMode::ANavesLAB01USFXGameMode()
{
    DefaultPawnClass = ANavesLAB01USFXPawn::StaticClass();
}

void ANavesLAB01USFXGameMode::BeginPlay()
{
    Super::BeginPlay();

    UWorld* World = GetWorld();
    if (!World) return;

    PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);

    // Generar enemigos
    GenerarEnemigos();

    // Generar muros
    GenerarMuros();
}

void ANavesLAB01USFXGameMode::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// ==================== MÉTODOS DE ENEMIGOS ====================

void ANavesLAB01USFXGameMode::GenerarEnemigos()
{
    UWorld* World = GetWorld();
    if (!World) return;

    // Posiciones diferentes para los enemigos
    TArray<FVector> Posiciones = {
        FVector(500, 500, 100),
        FVector(-500, 500, 100),
        FVector(500, -500, 100),
        FVector(-500, -500, 100),
        FVector(0, 800, 100),
        FVector(0, -800, 100),
        FVector(800, 0, 100),
        FVector(-800, 0, 100)
    };

    for (FVector Pos : Posiciones)
    {
        AEnemigo* NuevoEnemigo = World->SpawnActor<AEnemigo>(
            AEnemigo::StaticClass(),
            Pos,
            FRotator::ZeroRotator
        );

        if (NuevoEnemigo)
        {
            AEnemigos.Add(NuevoEnemigo);
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("Enemigos generados: %d"), AEnemigos.Num());
}

// ==================== MÉTODOS DE MUROS ====================

void ANavesLAB01USFXGameMode::GenerarMuros()
{
    UWorld* World = GetWorld();
    if (!World) return;

    MurosArray.Empty();

    // ===== MUROS DESLIZANTES =====
    // Esquina Superior Derecha
    CrearMuroDeslizante(World, FVector(1000, 800, 100), FVector(1, 0, 0), 400, 150);
    CrearMuroDeslizante(World, FVector(800, 1000, 100), FVector(0, 1, 0), 400, 150);

    // Esquina Superior Izquierda
    CrearMuroDeslizante(World, FVector(-1000, 800, 100), FVector(1, 0, 0), 400, 150);
    CrearMuroDeslizante(World, FVector(-800, 1000, 100), FVector(0, 1, 0), 400, 150);

    // Esquina Inferior Derecha
    CrearMuroDeslizante(World, FVector(1000, -800, 100), FVector(1, 0, 0), 400, 150);
    CrearMuroDeslizante(World, FVector(800, -1000, 100), FVector(0, 1, 0), 400, 150);

    // Esquina Inferior Izquierda
    CrearMuroDeslizante(World, FVector(-1000, -800, 100), FVector(1, 0, 0), 400, 150);
    CrearMuroDeslizante(World, FVector(-800, -1000, 100), FVector(0, 1, 0), 400, 150);

    // ===== MUROS PARPADEANTES =====
    CrearMuroParpadeante(World, FVector(-500, 1100, 100), 2.0f, 1.0f);
    CrearMuroParpadeante(World, FVector(0, 1150, 100), 3.0f, 1.5f);
    CrearMuroParpadeante(World, FVector(500, 1100, 100), 2.5f, 1.0f);

    CrearMuroParpadeante(World, FVector(-500, -1100, 100), 2.0f, 1.5f);
    CrearMuroParpadeante(World, FVector(0, -1150, 100), 3.0f, 1.0f);
    CrearMuroParpadeante(World, FVector(500, -1100, 100), 2.5f, 1.5f);

    CrearMuroParpadeante(World, FVector(1100, -500, 100), 2.0f, 1.0f);
    CrearMuroParpadeante(World, FVector(1150, 0, 100), 3.0f, 1.5f);
    CrearMuroParpadeante(World, FVector(1100, 500, 100), 2.5f, 1.0f);

    CrearMuroParpadeante(World, FVector(-1100, -500, 100), 2.0f, 1.5f);
    CrearMuroParpadeante(World, FVector(-1150, 0, 100), 3.0f, 1.0f);
    CrearMuroParpadeante(World, FVector(-1100, 500, 100), 2.5f, 1.5f);

    // ===== MUROS DIVISIBLES =====
    CrearMuroDivisible(World, FVector(1300, 1300, 100));
    CrearMuroDivisible(World, FVector(-1300, 1300, 100));
    CrearMuroDivisible(World, FVector(1300, -1300, 100));
    CrearMuroDivisible(World, FVector(-1300, -1300, 100));

    // ===== MUROS ESTÁTICOS =====
    CrearMuroEstatico(World, FVector(-900, 900, 100), FVector(4.0f, 1.0f, 2.0f));
    CrearMuroEstatico(World, FVector(0, 950, 100), FVector(6.0f, 1.0f, 2.0f));
    CrearMuroEstatico(World, FVector(900, 900, 100), FVector(4.0f, 1.0f, 2.0f));

    CrearMuroEstatico(World, FVector(-900, -900, 100), FVector(4.0f, 1.0f, 2.0f));
    CrearMuroEstatico(World, FVector(0, -950, 100), FVector(6.0f, 1.0f, 2.0f));
    CrearMuroEstatico(World, FVector(900, -900, 100), FVector(4.0f, 1.0f, 2.0f));

    UE_LOG(LogTemp, Warning, TEXT("Muros generados: %d"), MurosArray.Num());
}

// ==================== FUNCIONES DE CREACIÓN ====================

void ANavesLAB01USFXGameMode::CrearMuroDeslizante(UWorld* World, FVector Posicion, FVector Direccion, float Distancia, float Velocidad)
{
    AMuroDeslizante* Muro = World->SpawnActor<AMuroDeslizante>(AMuroDeslizante::StaticClass(), Posicion, FRotator::ZeroRotator);
    if (Muro)
    {
        MurosArray.Add(Muro);
    }
}

void ANavesLAB01USFXGameMode::CrearMuroParpadeante(UWorld* World, FVector Posicion, float TiempoVisible, float TiempoInvisible)
{
    AMuroParpadeante* Muro = World->SpawnActor<AMuroParpadeante>(AMuroParpadeante::StaticClass(), Posicion, FRotator::ZeroRotator);
    if (Muro)
    {
        MurosArray.Add(Muro);
    }
}

void ANavesLAB01USFXGameMode::CrearMuroDivisible(UWorld* World, FVector Posicion)
{
    AMuroDivisible* Muro = World->SpawnActor<AMuroDivisible>(AMuroDivisible::StaticClass(), Posicion, FRotator::ZeroRotator);
    if (Muro)
    {
        MurosArray.Add(Muro);
    }
}

void ANavesLAB01USFXGameMode::CrearMuroEstatico(UWorld* World, FVector Posicion, FVector Dimension)
{
    AMuroEstatico* Muro = World->SpawnActor<AMuroEstatico>(AMuroEstatico::StaticClass(), Posicion, FRotator::ZeroRotator);
    if (Muro)
    {
        Muro->Dimension = Dimension;
        Muro->ActualizarEscala();
        MurosArray.Add(Muro);
    }
}