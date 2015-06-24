#include "acoiffer.h"

ACoiffer::ACoiffer(SalleAttente* salle) : Client(1, salle)
{
	tempsDePousseDesCheveux = rand() % 5 + 2;
}

ACoiffer::~ACoiffer() {}

void ACoiffer::run()
{
	while (1)
	{
		sleep(tempsDePousseDesCheveux);
		salle.prendrePlace(this);
	}
}

