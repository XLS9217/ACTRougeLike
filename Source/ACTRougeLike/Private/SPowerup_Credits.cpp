
#include "SPowerup_Credits.h"
#include "SPlayerState.h"



ASPowerup_Credits::ASPowerup_Credits()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	// Disable collision, instead we use SphereComp to handle interaction queries
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshComp->SetupAttachment(RootComponent);

	CreditsAmount = 80;
}


void ASPowerup_Credits::Interact_Implementation(APawn* InstigatorPawn)
{
	if (!ensure(InstigatorPawn))
	{
		return;
	}

	if (ASPlayerState* PS = InstigatorPawn->GetPlayerState<ASPlayerState>())
	{
		PS->AddCredits(CreditsAmount);
		HideAndCooldownPowerup();
	}
}