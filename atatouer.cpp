#include "atatouer.h"

ATatouer::ATatouer(SalleAttente* salle) : Client(salle)
{
    tempsAvantTatouage = rand() % 3 * + 1;
}

ATatouer::~ATatouer() {}

int ATatouer::getTempsTatouage() {
    return tempsAvantTatouage;
}

void ATatouer::run()
{
    std::cout << "ATatouer #" << this->getId() << " is running." << std::endl;

    forever
	{
		sleep(tempsAvantTatouage);
        std::cout << "Le client #" << this->getId() << " veut un tatouage tribal de berger!" << std::endl;
		salle->prendrePlace(this);
		salle->attendreBarbier(this);
	}
}
