#include "FacadeJuego.h"
#include "Enemigo.h"
#include "EAAvion.h"
#include "EABarco.h"
#include "EADron.h"
#include "EAHelicoptero.h"
#include "EALancha.h"
#include "EAMotoAcuatica.h"
#include "ETBlindado.h"
#include "ETCamion.h"
#include "ETSoldado.h"
#include "ETTanque.h"


AFacadeJuego::AFacadeJuego()
{
 
	PrimaryActorTick.bCanEverTick = true;
    ClasesEnemigos.Add(AEAAvion::StaticClass());
    ClasesEnemigos.Add(AEABarco::StaticClass());
	ClasesEnemigos.Add(AEADron::StaticClass());
	ClasesEnemigos.Add(AEAHelicoptero::StaticClass());
	ClasesEnemigos.Add(AEALancha::StaticClass());
	ClasesEnemigos.Add(AEAMotoAcuatica::StaticClass());
	ClasesEnemigos.Add(AETBlindado::StaticClass());
	ClasesEnemigos.Add(AETCamion::StaticClass());
	ClasesEnemigos.Add(AETSoldado::StaticClass());
	ClasesEnemigos.Add(AETTanque::StaticClass());

}
void AFacadeJuego::GenerarCuadrilla(int cantidad)
{
	UWorld* World = GetWorld();
	FVector PosicionInicial = GetActorLocation();
    PosicionInicial.Z = 214.0f;
    float EspacioEje = 150;
	FVector Espaciado = FVector(150, 150, 0); // Espacio entre enemigos

    for (int i = 0; i < cantidad ; i++)
    {
        AEnemigo* Enemigo = World->SpawnActor<AEnemigo>(ClasesEnemigos[i], PosicionInicial + Espaciado * i, FRotator::ZeroRotator);
        if (Enemigo)
        {
            Cuadrilla.Add(Enemigo);
        }
    }
}
void AFacadeJuego::VerificarCuadrilla(float DeltaTime)
{
    // Recorrer hacia atrás para eliminar sin problemas
    for (int i = Cuadrilla.Num() - 1; i >= 0; i--)
    {
        // Verificar si el enemigo es nulo o está muerto
        if (Cuadrilla[i] == nullptr || !Cuadrilla[i]->bVivo)
        {
            if (Cuadrilla[i])
            {
                Cuadrilla[i]->Destroy();  
            }
            Cuadrilla.RemoveAt(i);  
        }
    }
    if (Cuadrilla.Num() == 0)
    {
        GenerarCuadrilla(ClasesEnemigos.Num());
        UE_LOG(LogTemp, Warning, TEXT("Cuadrilla regenerada"));
    }
}
void AFacadeJuego::BeginPlay()
{
	Super::BeginPlay();
	
}


void AFacadeJuego::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
     float TiempoActual = GetWorld()->GetTimeSeconds();
    if (TiempoActual > 1.0f) // esperar 1 segundo antes de verificar
        VerificarCuadrilla(DeltaTime);

}

