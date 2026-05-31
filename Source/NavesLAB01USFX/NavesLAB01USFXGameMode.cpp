#include "NavesLAB01USFXGameMode.h"
#include "NavesLAB01USFXPawn.h"
#include "Enemigo.h"
#include "EnemigoAereo.h"
#include "EnemigoTerrestre.h"
#include "EnemigoAcuatico.h"
#include "EAHelicoptero.h"
#include "EAAvion.h"
#include "EADron.h"
#include "ETSoldado.h"
#include "ETTanque.h"
#include "ETCamion.h"
#include "ETBlindado.h"
#include "EABarco.h"
#include "EALancha.h"
#include "EAMotoAcuatica.h"
#include "Muro.h"
#include "MuroDeslizante.h"
#include "MuroParpadeante.h"
#include "MuroDivisible.h"
#include "MuroEstatico.h"
#include "Kismet/GameplayStatics.h"

ANavesLAB01USFXGameMode::ANavesLAB01USFXGameMode()
{
    DefaultPawnClass = ANavesLAB01USFXPawn::StaticClass();
    CuadrillaActual = ECuadrilla::Primera;  // ? Inicializar cuadrilla
}  // ? CIERRE DEL CONSTRUCTOR

void ANavesLAB01USFXGameMode::BeginPlay()
{
    Super::BeginPlay();

    UWorld* World = GetWorld();
    if (!World) return;

    PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);

    GenerarCuadrilla1();
    GenerarMuros();

    GetWorldTimerManager().SetTimer(
        TimerRevisarCuadrilla,
        this,
        &ANavesLAB01USFXGameMode::RevisarCuadrilla,
        1.0f,
        true
    );
}

void ANavesLAB01USFXGameMode::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// ==================== GENERAR CUADRILLA 1 ====================

void ANavesLAB01USFXGameMode::GenerarCuadrilla1()
{
    UWorld* World = GetWorld();
    if (!World) return;

    Cuadrilla1.Empty();

    AEnemigo* H1 = World->SpawnActor<AEAHelicoptero>(AEAHelicoptero::StaticClass(), FVector(300, 300, 100), FRotator::ZeroRotator);
    if (H1) Cuadrilla1.Add(H1);

    AEnemigo* S1 = World->SpawnActor<AETSoldado>(AETSoldado::StaticClass(), FVector(-300, 300, 100), FRotator::ZeroRotator);
    if (S1) Cuadrilla1.Add(S1);

    AEnemigo* B1 = World->SpawnActor<AEABarco>(AEABarco::StaticClass(), FVector(300, -300, 100), FRotator::ZeroRotator);
    if (B1) Cuadrilla1.Add(B1);

    AEnemigo* H2 = World->SpawnActor<AEAHelicoptero>(AEAHelicoptero::StaticClass(), FVector(-300, -300, 100), FRotator::ZeroRotator);
    if (H2) Cuadrilla1.Add(H2);

    AEnemigo* S2 = World->SpawnActor<AETSoldado>(AETSoldado::StaticClass(), FVector(0, 400, 100), FRotator::ZeroRotator);
    if (S2) Cuadrilla1.Add(S2);

    AEnemigo* B2 = World->SpawnActor<AEABarco>(AEABarco::StaticClass(), FVector(0, -400, 100), FRotator::ZeroRotator);
    if (B2) Cuadrilla1.Add(B2);

    AEnemigo* A1 = World->SpawnActor<AEAAvion>(AEAAvion::StaticClass(), FVector(400, 0, 100), FRotator::ZeroRotator);
    if (A1) Cuadrilla1.Add(A1);

    AEnemigo* T1 = World->SpawnActor<AETTanque>(AETTanque::StaticClass(), FVector(-400, 0, 100), FRotator::ZeroRotator);
    if (T1) Cuadrilla1.Add(T1);

    UE_LOG(LogTemp, Warning, TEXT("Cuadrilla 1: %d enemigos"), Cuadrilla1.Num());
}

// ==================== GENERAR CUADRILLA 2 ====================

void ANavesLAB01USFXGameMode::GenerarCuadrilla2()
{
    UWorld* World = GetWorld();
    if (!World) return;

    Cuadrilla2.Empty();

    AEnemigo* D1 = World->SpawnActor<AEADron>(AEADron::StaticClass(), FVector(1200, 800, 100), FRotator::ZeroRotator);
    if (D1) Cuadrilla2.Add(D1);

    AEnemigo* C1 = World->SpawnActor<AETCamion>(AETCamion::StaticClass(), FVector(-1200, 800, 100), FRotator::ZeroRotator);
    if (C1) Cuadrilla2.Add(C1);

    AEnemigo* L1 = World->SpawnActor<AEALancha>(AEALancha::StaticClass(), FVector(1200, -800, 100), FRotator::ZeroRotator);
    if (L1) Cuadrilla2.Add(L1);

    AEnemigo* BL1 = World->SpawnActor<AETBlindado>(AETBlindado::StaticClass(), FVector(-1200, -800, 100), FRotator::ZeroRotator);
    if (BL1) Cuadrilla2.Add(BL1);

    AEnemigo* D2 = World->SpawnActor<AEADron>(AEADron::StaticClass(), FVector(0, 1300, 100), FRotator::ZeroRotator);
    if (D2) Cuadrilla2.Add(D2);

    AEnemigo* M1 = World->SpawnActor<AEAMotoAcuatica>(AEAMotoAcuatica::StaticClass(), FVector(0, -1300, 100), FRotator::ZeroRotator);
    if (M1) Cuadrilla2.Add(M1);

    AEnemigo* A1 = World->SpawnActor<AEAAvion>(AEAAvion::StaticClass(), FVector(1300, 0, 100), FRotator::ZeroRotator);
    if (A1) Cuadrilla2.Add(A1);

    AEnemigo* T1 = World->SpawnActor<AETTanque>(AETTanque::StaticClass(), FVector(-1300, 0, 100), FRotator::ZeroRotator);
    if (T1) Cuadrilla2.Add(T1);

    AEnemigo* L2 = World->SpawnActor<AEALancha>(AEALancha::StaticClass(), FVector(900, 900, 100), FRotator::ZeroRotator);
    if (L2) Cuadrilla2.Add(L2);

    AEnemigo* BL2 = World->SpawnActor<AETBlindado>(AETBlindado::StaticClass(), FVector(-900, -900, 100), FRotator::ZeroRotator);
    if (BL2) Cuadrilla2.Add(BL2);

    UE_LOG(LogTemp, Warning, TEXT("Cuadrilla 2: %d enemigos"), Cuadrilla2.Num());
}

// ==================== REVISAR CUADRILLA ====================

void ANavesLAB01USFXGameMode::RevisarCuadrilla()
{
    if (CuadrillaActual == ECuadrilla::Primera)
    {
        for (int i = Cuadrilla1.Num() - 1; i >= 0; i--)
        {
            if (Cuadrilla1[i] == nullptr)
            {
                Cuadrilla1.RemoveAt(i);
            }
        }

        if (Cuadrilla1.Num() == 0)
        {
            UE_LOG(LogTemp, Warning, TEXT("Cuadrilla 1 destruida! Generando Cuadrilla 2..."));
            CuadrillaActual = ECuadrilla::Segunda;
            GenerarCuadrilla2();
        }
    }
    else if (CuadrillaActual == ECuadrilla::Segunda)
    {
        for (int i = Cuadrilla2.Num() - 1; i >= 0; i--)
        {
            if (Cuadrilla2[i] == nullptr)
            {
                Cuadrilla2.RemoveAt(i);
            }
        }

        if (Cuadrilla2.Num() == 0)
        {
            UE_LOG(LogTemp, Warning, TEXT("TODOS LOS ENEMIGOS DESTRUIDOS!"));
            GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("¡VICTORIA!"));
            GetWorldTimerManager().ClearTimer(TimerRevisarCuadrilla);
        }
    }
}

void ANavesLAB01USFXGameMode::LimpiarCuadrillas()
{
    Cuadrilla1.Empty();
    Cuadrilla2.Empty();
}

// ==================== MUROS ====================

void ANavesLAB01USFXGameMode::GenerarMuros()
{
    UWorld* World = GetWorld();
    if (!World) return;

    MurosArray.Empty();

    CrearMuroDeslizante(World, FVector(1000, 800, 100), FVector(1, 0, 0), 400, 150);
    CrearMuroDeslizante(World, FVector(800, 1000, 100), FVector(0, 1, 0), 400, 150);
    CrearMuroDeslizante(World, FVector(-1000, 800, 100), FVector(1, 0, 0), 400, 150);
    CrearMuroDeslizante(World, FVector(-800, 1000, 100), FVector(0, 1, 0), 400, 150);
    CrearMuroDeslizante(World, FVector(1000, -800, 100), FVector(1, 0, 0), 400, 150);
    CrearMuroDeslizante(World, FVector(800, -1000, 100), FVector(0, 1, 0), 400, 150);
    CrearMuroDeslizante(World, FVector(-1000, -800, 100), FVector(1, 0, 0), 400, 150);
    CrearMuroDeslizante(World, FVector(-800, -1000, 100), FVector(0, 1, 0), 400, 150);

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

    CrearMuroDivisible(World, FVector(1300, 1300, 100));
    CrearMuroDivisible(World, FVector(-1300, 1300, 100));
    CrearMuroDivisible(World, FVector(1300, -1300, 100));
    CrearMuroDivisible(World, FVector(-1300, -1300, 100));

    CrearMuroEstatico(World, FVector(-900, 900, 100), FVector(4.0f, 1.0f, 2.0f));
    CrearMuroEstatico(World, FVector(0, 950, 100), FVector(6.0f, 1.0f, 2.0f));
    CrearMuroEstatico(World, FVector(900, 900, 100), FVector(4.0f, 1.0f, 2.0f));
    CrearMuroEstatico(World, FVector(-900, -900, 100), FVector(4.0f, 1.0f, 2.0f));
    CrearMuroEstatico(World, FVector(0, -950, 100), FVector(6.0f, 1.0f, 2.0f));
    CrearMuroEstatico(World, FVector(900, -900, 100), FVector(4.0f, 1.0f, 2.0f));
}

void ANavesLAB01USFXGameMode::CrearMuroDeslizante(UWorld* World, FVector Posicion, FVector Direccion, float Distancia, float Velocidad)
{
    AMuroDeslizante* Muro = World->SpawnActor<AMuroDeslizante>(AMuroDeslizante::StaticClass(), Posicion, FRotator::ZeroRotator);
    if (Muro) MurosArray.Add(Muro);
}

void ANavesLAB01USFXGameMode::CrearMuroParpadeante(UWorld* World, FVector Posicion, float TiempoVisible, float TiempoInvisible)
{
    AMuroParpadeante* Muro = World->SpawnActor<AMuroParpadeante>(AMuroParpadeante::StaticClass(), Posicion, FRotator::ZeroRotator);
    if (Muro) MurosArray.Add(Muro);
}

void ANavesLAB01USFXGameMode::CrearMuroDivisible(UWorld* World, FVector Posicion)
{
    AMuroDivisible* Muro = World->SpawnActor<AMuroDivisible>(AMuroDivisible::StaticClass(), Posicion, FRotator::ZeroRotator);
    if (Muro) MurosArray.Add(Muro);
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