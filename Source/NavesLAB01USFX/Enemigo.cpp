#include "Enemigo.h"
#include "NavesLAB01USFXPawn.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "NavesLAB01USFXProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "MuroEstatico.h"

AEnemigo::AEnemigo()
{
    PrimaryActorTick.bCanEverTick = true;
    VidaActual = VidaMaxima;

    MallaEnemigo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaEnemigo"));
    RootComponent = MallaEnemigo;
    bVivo = true;
    MallaEnemigo->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    MallaEnemigo->SetCollisionObjectType(ECC_PhysicsBody);
    MallaEnemigo->SetCollisionResponseToAllChannels(ECR_Block);
    MallaEnemigo->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
    MallaEnemigo->SetSimulatePhysics(true);
    MallaEnemigo->OnComponentHit.AddDynamic(this, &AEnemigo::OnHit);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(
        TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'")
    );
    if (MallaAsset.Succeeded())
    {
        MallaEnemigo->SetStaticMesh(MallaAsset.Object);
    }
	DireccionMovimiento = FVector(1, 1, 0);
    rango = FVector(1200,1000,0);
}

void AEnemigo::BeginPlay()
{
    Super::BeginPlay();
    MallaEnemigo->SetSimulatePhysics(false);
    APlayerController* PC = GetWorld()->GetFirstPlayerController();
    if (PC)
    {
        Jugador = Cast<ANavesLAB01USFXPawn>(PC->GetPawn());
    }

    PosicionInicial = GetActorLocation();
    EscalaActual = 1.0f;
    CargarRuta();
}

void AEnemigo::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bCambiarEscala)
    {
        CambiarEscala(DeltaTime);
    }

    Moverse(DeltaTime);
    Disparar();
    ActualizarEfecto(DeltaTime);
}

// ===== MOVIMIENTO PRINCIPAL =====
void AEnemigo::Moverse(float DeltaTime)
{
    // 1. Modo rodear nave (SOLO PARA LAS DONAS)
    if (bRodearNave)
    {
        MoverRodearNave(DeltaTime);
        return;
    }

    // 2. Modo autónomo (PARA LAS HIJAS)
    if (!bMovimientoAutonomo) return;

    if (PosicionInicial.IsZero())
    {
        PosicionInicial = GetActorLocation();
    }
    if (FMath::Abs(GetActorLocation().X - PosicionInicial.X) > rango.X)
    {
        DireccionMovimiento.X = -DireccionMovimiento.X;
       
    }
    if (FMath::Abs(GetActorLocation().Y - PosicionInicial.Y) > rango.Y)
    {
        DireccionMovimiento.Y = -DireccionMovimiento.Y;
        
    }
    FVector NuevaPosicion = GetActorLocation();

    switch (TipoMovimiento) 
    {
    case 0: // Recto
        NuevaPosicion += FVector(Velocidad * DeltaTime * DireccionMovimiento.X, 0, 0);
        break;

    case 1: // Zigzag
    {
        float Tiempo = GetWorld()->GetTimeSeconds();
        float OffsetY = FMath::Sin(Tiempo * 3.0f) * 100.0f;
        NuevaPosicion += FVector(Velocidad * DeltaTime * DireccionMovimiento.X, OffsetY * DeltaTime, 0);
    }
    break;

    case 2: // Circular
    {
        float Tiempo = GetWorld()->GetTimeSeconds();
        float Radio = 200.0f;
        float VelocidadAngularMov = 2.0f;
        float Angulo = Tiempo * VelocidadAngularMov;
        FVector Centro = PosicionInicial;
        NuevaPosicion.X = Centro.X + FMath::Cos(Angulo) * Radio * DireccionMovimiento.X;
        NuevaPosicion.Y = Centro.Y + FMath::Sin(Angulo) * Radio * DireccionMovimiento.Y;
    }
    break;

    case 3: // Senoide
    {
        float Tiempo = GetWorld()->GetTimeSeconds();
        float OffsetY = FMath::Sin(Tiempo * 2.0f) * 150.0f;
        NuevaPosicion += FVector(Velocidad * DeltaTime * DireccionMovimiento.X, OffsetY * DeltaTime, 0);
    }
    break;

    default:
        NuevaPosicion += FVector(Velocidad * DeltaTime * DireccionMovimiento.X, 0, 0);
        break;
    }

    SetActorLocation(NuevaPosicion);
    
}

// ===== RUTA =====
void AEnemigo::CargarRuta()
{
    PuntosRuta.Empty();

    float Tamano = 300.0f;
    float Z = PosicionInicial.Z;

    FVector V1 = FVector(PosicionInicial.X, PosicionInicial.Y + Tamano, Z);
    FVector V2 = FVector(PosicionInicial.X + Tamano, PosicionInicial.Y - Tamano, Z);
    FVector V3 = FVector(PosicionInicial.X - Tamano, PosicionInicial.Y - Tamano, Z);

    PuntosRuta.Add(V1);
    PuntosRuta.Add(V2);
    PuntosRuta.Add(V3);
    PuntosRuta.Add(V1);

    IndicePuntoRutaActual = 0;
}

// ===== ESCALADO =====
void AEnemigo::CambiarEscala(float DeltaTime)
{
    if (bAumentando)
    {
        EscalaActual += VelocidadEscala * DeltaTime;
        if (EscalaActual >= EscalaMaxima)
        {
            EscalaActual = EscalaMaxima;
            bAumentando = false;
        }
    }
    else
    {
        EscalaActual -= VelocidadEscala * DeltaTime;
        if (EscalaActual <= EscalaMinima)
        {
            EscalaActual = EscalaMinima;
            bAumentando = true;
        }
    }
    SetActorScale3D(FVector(EscalaActual));
}

// ===== RODEAR NAVE =====
void AEnemigo::ActivarRodearNave(FVector Centro, float NuevoRadio, float VelocidadNueva)
{
    bRodearNave = true;
    bMovimientoAutonomo = false;
    CentroRodear = Centro;
    RadioRodear = NuevoRadio;
    VelocidadAngular = VelocidadNueva;
}

void AEnemigo::DesactivarRodearNave()
{
    bRodearNave = false;
    bMovimientoAutonomo = true;
}

void AEnemigo::MoverRodearNave(float DeltaTime)
{
    if (!bRodearNave) return;

    AnguloActual += VelocidadAngular * DeltaTime;
    if (AnguloActual >= 360.0f) AnguloActual -= 360.0f;

    float Rad = FMath::DegreesToRadians(AnguloActual);
    float NuevaX = CentroRodear.X + RadioRodear * FMath::Cos(Rad);
    float NuevaY = CentroRodear.Y + RadioRodear * FMath::Sin(Rad);

    SetActorLocation(FVector(NuevaX, NuevaY, GetActorLocation().Z));
}

// ===== VIDA Y DAÑO =====
void AEnemigo::Atacar(AActor* Objetivo)
{
    ANavesLAB01USFXPawn* Nave = Cast<ANavesLAB01USFXPawn>(Objetivo);
    if (Nave)
    {
        Nave->RecibirDanio(Dano);
        UE_LOG(LogTemp, Warning, TEXT("Enemigo ataco a la nave - Dano: %.0f"), Dano);
    }
}

void AEnemigo::RecibirDanio(float Cantidad)
{
    VidaActual -= Cantidad;
    UE_LOG(LogTemp, Warning, TEXT("Enemigo recibe danio: %.0f, Vida restante: %.0f"), Cantidad, VidaActual);
    if (VidaActual <= 0.0f)
    {
		bVivo = false;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Enemigo destruido"));
		Destroy();
    }
}

void AEnemigo::ActualizarEfecto(float DeltaTime) {}
void AEnemigo::Disparar() {}

void AEnemigo::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Result)
{
    if (OtherActor == Jugador)
    {
		//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("Enemigo ataco a la nave por colision"));
        Atacar(OtherActor);
    }
}