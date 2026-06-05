#include "Muro.h"
#include "Engine/StaticMesh.h"
#include "Components/StaticMeshComponent.h"

AMuro::AMuro()
{
	PrimaryActorTick.bCanEverTick = true;

	MallaMuro = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaMuro"));
	RootComponent = MallaMuro;
	SetForma(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));

	// Configuración de colisiones
	MallaMuro->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	MallaMuro->SetCollisionObjectType(ECC_WorldStatic);
	MallaMuro->SetSimulatePhysics(false);
	MallaMuro->SetNotifyRigidBodyCollision(true);
	MallaMuro->SetCollisionResponseToAllChannels(ECR_Block);
	

	Dimension = FVector(3.0f, 1.0f, 2.0f);
}

void AMuro::BeginPlay()
{
	Super::BeginPlay();
	ActualizarEscala();
}

void AMuro::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ActualizarEfecto(DeltaTime);
}

void AMuro::ActualizarEscala()
{
	MallaMuro->SetWorldScale3D(Dimension);
}

void AMuro::ActualizarEfecto(float DeltaTime)
{
	// Vacío - las hijas lo sobrescriben
}

void AMuro::RecibirDanio(float Cantidad)
{
	Resistencia -= Cantidad;
	if (Resistencia <= 0.0f)
	{
		DestruirMuro();
	}
}

void AMuro::DestruirMuro()
{
	Destroy();
}

void AMuro::SetForma(const TCHAR* rutaForma)
{
	ConstructorHelpers::FObjectFinder<UStaticMesh> Forma(rutaForma);
	if (Forma.Succeeded())
	{
		MallaMuro->SetStaticMesh(Forma.Object);
	}
}