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
#include "BloqueCamino.h"
#include "Muro.h"
#include "MuroDeslizante.h"
#include "MuroParpadeante.h"
#include "MuroDivisible.h"
#include "MuroEstatico.h"
#include "FacadeJuego.h"
#include "Kismet/GameplayStatics.h"

ANavesLAB01USFXGameMode::ANavesLAB01USFXGameMode()
{
    DefaultPawnClass = ANavesLAB01USFXPawn::StaticClass();
    CuadrillaActual = ECuadrilla::Primera;
    bEnFormacion = false;
}

void ANavesLAB01USFXGameMode::BeginPlay()
{
    Super::BeginPlay();

    UWorld* World = GetWorld();
    if (!World) return;

    PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	FacadeJuego = World->SpawnActor<AFacadeJuego>(AFacadeJuego::StaticClass(), FVector(-990,10,300), FRotator::ZeroRotator);
	FacadeJuego->GenerarCuadrilla(10);

    // ===== 1.EFECTO DE ENEMIGO =====
    for (int i = 0; i < 10; i++)
    {
        float Angulo = (360.0f / 10) * i;
        float Rad = FMath::DegreesToRadians(Angulo);
        float Radio = 400.0f;

        float X = PlayerPawn->GetActorLocation().X + Radio * FMath::Cos(Rad);
        float Y = PlayerPawn->GetActorLocation().Y + Radio * FMath::Sin(Rad);
        FVector Posicion = FVector(X, Y, 200.0f);

        AEnemigo* Enemigo = World->SpawnActor<AEnemigo>(AEnemigo::StaticClass(), Posicion, FRotator::ZeroRotator);
        if (Enemigo)
        {
            Enemigo->ActivarRodearNave(PlayerPawn->GetActorLocation(), Radio, 100.0f + 10 * i);
            Enemigo->bCambiarEscala = true;
            ListaEnemigos.Add(Enemigo);
        }
    }
    // ===== 4. GENERAR MUROS Y CAMINOS =====
    //GenerarMuros();
    GenerarCamino();
    // ===== 5. TIMERS =====
    GetWorldTimerManager().SetTimer(TimerCambioModo, this, &ANavesLAB01USFXGameMode::CambiarModo, 5.0f, true);

    

}

void ANavesLAB01USFXGameMode::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    //Actualizar el centro de las donas para que sigan al jugador
    if (PlayerPawn)
    {
        for (AEnemigo* Enemigo : ListaEnemigos)
        {
            if (Enemigo && Enemigo->bRodearNave)
            {
                Enemigo->CentroRodear = PlayerPawn->GetActorLocation();
            }
        }
    }
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

    GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("FORMACION: Naves en circulo"));
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
}


void ANavesLAB01USFXGameMode::CambiarModo()
{
    if (bEnFormacion)
    {
        bEnFormacion = false;
        ModoAutonomo();
        GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT("AUTONOMO: Naves en movimiento"));
    }
    else
    {
        bEnFormacion = true;
        FormarNaves();
    }
}


void ANavesLAB01USFXGameMode::GenerarMuros()
{
    UWorld* World = GetWorld();
    if (!World) return;

    MurosArray.Empty();

    CrearMuroDeslizante(World, FVector(0, 1500, 150), FVector(1, 0, 0), 800, 150);
    CrearMuroDeslizante(World, FVector(0, -1500, 150), FVector(1, 0, 0), 800, 150);
    CrearMuroDeslizante(World, FVector(1500, 0, 150), FVector(0, 1, 0), 800, 150);
    CrearMuroDeslizante(World, FVector(-1500, 0, 150), FVector(0, 1, 0), 800, 150);

    CrearMuroParpadeante(World, FVector(800, 1300, 150), 2.0f, 1.0f);
    CrearMuroParpadeante(World, FVector(-800, 1300, 150), 2.0f, 1.0f);
    CrearMuroParpadeante(World, FVector(800, -1300, 150), 2.0f, 1.0f);
    CrearMuroParpadeante(World, FVector(-800, -1300, 150), 2.0f, 1.0f);

    CrearMuroDivisible(World, FVector(1800, 0, 150));
    CrearMuroDivisible(World, FVector(-1800, 0, 150));

    CrearMuroEstatico(World, FVector(500, 1200, 150), FVector(5.0f, 1.0f, 3.0f));
    CrearMuroEstatico(World, FVector(-500, 1200, 150), FVector(5.0f, 1.0f, 3.0f));
    CrearMuroEstatico(World, FVector(500, -1200, 150), FVector(5.0f, 1.0f, 3.0f));
    CrearMuroEstatico(World, FVector(-500, -1200, 150), FVector(5.0f, 1.0f, 3.0f));

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

// ==================== CAMINO ====================

void ANavesLAB01USFXGameMode::GenerarCamino()
{
    UWorld* World = GetWorld();
    if (!World) return;

    ListaBloques.Empty();


    float Espacio = 200.0f;
    float InicioX = -400.0f;
    float InicioY = -400.0f;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
           /* if (Mapa[i][j] == 1)
            {
                FVector Posicion(InicioX + j * Espacio, InicioY + i * Espacio, 50.0f);
                ABloqueCamino* Bloque = World->SpawnActor<ABloqueCamino>(ABloqueCamino::StaticClass(), Posicion, FRotator::ZeroRotator);
                if (Bloque)
                {
                    Bloque->bEsCamino = true;
                    ListaBloques.Add(Bloque);
                }
            }*/
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("Camino generado: %d bloques"), ListaBloques.Num());
}