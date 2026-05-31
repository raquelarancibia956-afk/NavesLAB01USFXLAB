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
    CuadrillaActual = ECuadrilla::Primera;  
} 
void ANavesLAB01USFXGameMode::BeginPlay()
{
    Super::BeginPlay();

    UWorld* World = GetWorld();
    if (!World) return;

    PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);

    //Generar las 20 naves
    GenerarContenedorNaves();
    bEnFormacion = false;

    // Timer para cambiar modo cada 5 segundos
    GetWorldTimerManager().SetTimer(TimerCambioModo, this, &ANavesLAB01USFXGameMode::CambiarModo, 5.0f, true);

    GenerarCuadrilla1();
    GenerarMuros();

    GetWorldTimerManager().SetTimer(TimerRevisarCuadrilla, this, &ANavesLAB01USFXGameMode::RevisarCuadrilla, 1.0f, true);
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

    // ===== MUROS DESLIZANTES (8) =====
    // Arriba
    CrearMuroDeslizante(World, FVector(0, 1500, 150), FVector(1, 0, 0), 800, 150);
    // Abajo
    CrearMuroDeslizante(World, FVector(0, -1500, 150), FVector(1, 0, 0), 800, 150);
    // Derecha
    CrearMuroDeslizante(World, FVector(1500, 0, 150), FVector(0, 1, 0), 800, 150);
    // Izquierda
    CrearMuroDeslizante(World, FVector(-1500, 0, 150), FVector(0, 1, 0), 800, 150);

    // Esquinas
    CrearMuroDeslizante(World, FVector(1200, 1200, 150), FVector(1, 1, 0), 400, 150);
    CrearMuroDeslizante(World, FVector(-1200, 1200, 150), FVector(-1, 1, 0), 400, 150);
    CrearMuroDeslizante(World, FVector(1200, -1200, 150), FVector(1, -1, 0), 400, 150);
    CrearMuroDeslizante(World, FVector(-1200, -1200, 150), FVector(-1, -1, 0), 400, 150);

    // ===== MUROS PARPADEANTES (8) =====
    CrearMuroParpadeante(World, FVector(800, 1300, 150), 2.0f, 1.0f);
    CrearMuroParpadeante(World, FVector(-800, 1300, 150), 2.0f, 1.0f);
    CrearMuroParpadeante(World, FVector(800, -1300, 150), 2.0f, 1.0f);
    CrearMuroParpadeante(World, FVector(-800, -1300, 150), 2.0f, 1.0f);
    CrearMuroParpadeante(World, FVector(1300, 800, 150), 2.0f, 1.0f);
    CrearMuroParpadeante(World, FVector(-1300, 800, 150), 2.0f, 1.0f);
    CrearMuroParpadeante(World, FVector(1300, -800, 150), 2.0f, 1.0f);
    CrearMuroParpadeante(World, FVector(-1300, -800, 150), 2.0f, 1.0f);

    // ===== MUROS DIVISIBLES (4) =====
    CrearMuroDivisible(World, FVector(1800, 0, 150));
    CrearMuroDivisible(World, FVector(-1800, 0, 150));
    CrearMuroDivisible(World, FVector(0, 1800, 150));
    CrearMuroDivisible(World, FVector(0, -1800, 150));

    // ===== MUROS ESTÁTICOS (8) =====
    CrearMuroEstatico(World, FVector(500, 1200, 150), FVector(5.0f, 1.0f, 3.0f));
    CrearMuroEstatico(World, FVector(-500, 1200, 150), FVector(5.0f, 1.0f, 3.0f));
    CrearMuroEstatico(World, FVector(500, -1200, 150), FVector(5.0f, 1.0f, 3.0f));
    CrearMuroEstatico(World, FVector(-500, -1200, 150), FVector(5.0f, 1.0f, 3.0f));
    CrearMuroEstatico(World, FVector(1200, 500, 150), FVector(1.0f, 5.0f, 3.0f));
    CrearMuroEstatico(World, FVector(1200, -500, 150), FVector(1.0f, 5.0f, 3.0f));
    CrearMuroEstatico(World, FVector(-1200, 500, 150), FVector(1.0f, 5.0f, 3.0f));
    CrearMuroEstatico(World, FVector(-1200, -500, 150), FVector(1.0f, 5.0f, 3.0f));

    UE_LOG(LogTemp, Warning, TEXT("Muros generados: %d"), MurosArray.Num());
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
// ==================== CONTENEDOR DE 20 NAVES ====================

void ANavesLAB01USFXGameMode::GenerarContenedorNaves()
{
    UWorld* World = GetWorld();
    if (!World) return;

    ContenedorNaves.Empty();

    for (int i = 0; i < 20; i++)
    {
        float X = FMath::RandRange(-1500.0f, 1500.0f);
        float Y = FMath::RandRange(-1500.0f, 1500.0f);
        FVector Posicion = FVector(X, Y, 100.0f);

        AEnemigo* NuevaNave = nullptr;

        switch (i % 6)
        {
        case 0: NuevaNave = World->SpawnActor<AEAHelicoptero>(AEAHelicoptero::StaticClass(), Posicion, FRotator::ZeroRotator); break;
        case 1: NuevaNave = World->SpawnActor<AEAAvion>(AEAAvion::StaticClass(), Posicion, FRotator::ZeroRotator); break;
        case 2: NuevaNave = World->SpawnActor<AEADron>(AEADron::StaticClass(), Posicion, FRotator::ZeroRotator); break;
        case 3: NuevaNave = World->SpawnActor<AETSoldado>(AETSoldado::StaticClass(), Posicion, FRotator::ZeroRotator); break;
        case 4: NuevaNave = World->SpawnActor<AETTanque>(AETTanque::StaticClass(), Posicion, FRotator::ZeroRotator); break;
        case 5: NuevaNave = World->SpawnActor<AEABarco>(AEABarco::StaticClass(), Posicion, FRotator::ZeroRotator); break;
        }

        if (NuevaNave)
        {
            NuevaNave->bMovimientoAutonomo = true;
            NuevaNave->PosicionInicial = Posicion;
            ContenedorNaves.Add(NuevaNave);
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("Contenedor: 20 naves creadas"));
}

void ANavesLAB01USFXGameMode::FormarNaves()
{
    if (!PlayerPawn) return;

    FVector Centro = PlayerPawn->GetActorLocation();
    Centro.Z += 100.0f;

    float Radio = 500.0f;
    int TotalNaves = ContenedorNaves.Num();

    for (int i = 0; i < TotalNaves; i++)
    {
        if (AEnemigo* Nave = ContenedorNaves[i])
        {
            float Angulo = (360.0f / TotalNaves) * i;
            float Rad = FMath::DegreesToRadians(Angulo);

            float X = Centro.X + Radio * FMath::Cos(Rad);
            float Y = Centro.Y + Radio * FMath::Sin(Rad);
            FVector NuevaPos = FVector(X, Y, Centro.Z);

            Nave->SetActorLocation(NuevaPos);
            Nave->bMovimientoAutonomo = false;
            Nave->PosicionInicial = NuevaPos;
        }
    }

    GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("FORMACION: Circulo"));
}

void ANavesLAB01USFXGameMode::ModoAutonomo()
{
    for (AEnemigo* Nave : ContenedorNaves)
    {
        if (Nave)
        {
            Nave->bMovimientoAutonomo = true;
            Nave->PosicionInicial = Nave->GetActorLocation();  
        }
    }
    GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT("AUTONOMO: Naves en movimiento"));
}

void ANavesLAB01USFXGameMode::CambiarModo()
{
    if (bEnFormacion)
    {
        bEnFormacion = false;
        ModoAutonomo();
        GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT("MODO AUToNOMO"));
    }
    else
    {
        bEnFormacion = true;
        FormarNaves();
        GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("MODO FORMACIoN"));
    }
}