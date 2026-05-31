#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Muro.generated.h"

UCLASS()
class NAVESLAB01USFX_API AMuro : public AActor
{
	GENERATED_BODY()

public:
	AMuro();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Muro")
	UStaticMeshComponent* MallaMuro;

	// Propiedades básicas
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Muro")
	float Resistencia = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Muro")
	FVector Dimension;

	virtual void RecibirDanio(float Cantidad);
	virtual void DestruirMuro();
	void ActualizarEscala();

protected:
	virtual void BeginPlay() override;
	void SetForma(const TCHAR* rutaForma);

public:
	virtual void Tick(float DeltaTime) override;
	virtual void ActualizarEfecto(float DeltaTime);
};