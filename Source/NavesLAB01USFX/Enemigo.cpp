#include "Enemigo.h"
#include "NavesLAB01USFXPawn.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"

AEnemigo::AEnemigo()
{
	PrimaryActorTick.bCanEverTick = true;
	VidaActual = VidaMaxima;

	MallaEnemigo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaEnemigo"));
	RootComponent = MallaEnemigo;

	MallaEnemigo->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	MallaEnemigo->SetCollisionObjectType(ECC_PhysicsBody);
	MallaEnemigo->SetCollisionResponseToAllChannels(ECR_Block);
	MallaEnemigo->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
	MallaEnemigo->SetSimulatePhysics(true);

	MallaEnemigo->OnComponentHit.AddDynamic(this, &AEnemigo::OnHit);

	// Cargar malla por defecto
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(
		TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'")
	);
	if (MallaAsset.Succeeded())
	{
		MallaEnemigo->SetStaticMesh(MallaAsset.Object);
	}
}

void AEnemigo::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (PC)
	{
		Jugador = Cast<ANavesLAB01USFXPawn>(PC->GetPawn());
	}

	CargarRuta(); // Llamar a la ruta
}

void AEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Moverse(DeltaTime);
	Disparar();
	ActualizarEfecto(DeltaTime);
}

void AEnemigo::Moverse(float DeltaTime)
{
	if (Jugador)
	{
		FVector Direccion = Jugador->GetActorLocation() - GetActorLocation();
		Direccion.Normalize();

		FVector NuevaPosicion = GetActorLocation() + Direccion * Velocidad * DeltaTime;
		SetActorLocation(NuevaPosicion);

		FRotator Rotacion = Direccion.Rotation();
		SetActorRotation(Rotacion);
	}
}

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
		Destroy();
	}
}

void AEnemigo::ActualizarEfecto(float DeltaTime)
{
	// Vacio
}

void AEnemigo::Disparar()
{
	// Vacio
}

void AEnemigo::CargarRuta()
{
	// Por defecto no hace nada
}

void AEnemigo::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Result)
{
	Atacar(OtherActor);
}