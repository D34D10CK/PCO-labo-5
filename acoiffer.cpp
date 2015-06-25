#include "acoiffer.h"
#include "atatouer.h"

ACoiffer::ACoiffer(SalleAttente* salle) : Client(salle)
{
	tempsDePousseDesCheveux = rand() % 5 + 2;
}

ACoiffer::~ACoiffer() {}

void ACoiffer::run()
{
    forever
	{
		sleep(tempsDePousseDesCheveux);
        salle->prendrePlace(this);
        salle->attendreBarbier(this);
	}
}

int ACoiffer::getTempsPousse()
{
	return tempsDePousseDesCheveux;
}

