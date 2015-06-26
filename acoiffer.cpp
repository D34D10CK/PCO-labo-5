#include "acoiffer.h"
#include "atatouer.h"

ACoiffer::ACoiffer(SalleAttente* salle) : Client(salle)
{
	tempsDePousseDesCheveux = rand() % 5 + 2;
}

ACoiffer::~ACoiffer() {}

void ACoiffer::run()
{
    std::cout << "ACoiffer #" << this->getId() << " is running." << std::endl;

    forever
	{
		sleep(tempsDePousseDesCheveux);
        std::cout << "Les cheveux du client #" << this->getId() << " sont trop longs!" << std::endl;
        salle->prendrePlace(this);
        salle->attendreBarbier(this);
	}
}

int ACoiffer::getTempsPousse()
{
	return tempsDePousseDesCheveux;
}
