#include "atatouer.h"

ATatouer::ATatouer(SalleAttente* salle) : Client(salle)
{
	tempsAvantTatouage = rand() % 3 * + 1
}

ATatouer::~ATatouer() {}

void ATatouer::run()
{
	while (1)
	{
		sleep(tempsAvantTatouage);
		salle->prendrePlace(this);
		salle->attendreBarbier(this);
	}
}
