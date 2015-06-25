#include "salleattente.h"
#include "client.h"
#include "acoiffer.h"
#include "atatouer.h"
#include <iostream>

SalleAttente::SalleAttente(int taille): nbSieges(taille) {}

SalleAttente::~SalleAttente() {}

void SalleAttente::prendrePlace(ACoiffer* client)
{
	mutex1.lock();
	if (placesOccupees < nbSieges)
	{
		aCoiffer.enqueue(client);
		placesOccupees++;
		std::cout << "le client " << client->getId() << " entre dans la salle d'attente." << std::endl;
		mutex1.unlock();
	}
	else
	{
        vaFaireUnTour.wait(&mutex1, (1000 * client->getTempsPousse()) / 2);
		std::cout << "le client " << client->getId() << " va faire un tour." << std::endl;
		mutex1.unlock();
		prendrePlace(client);
	}
}

void SalleAttente::attendreBarbier(Client* client)
{
	mutex2.lock();
    attendreBarbierCondition.wait(&mutex2);
	mutex2.unlock();
}

void SalleAttente::prendrePlace(ATatouer* client)
{
	mutex1.lock();
	if (placesOccupees < nbSieges)
	{
		aTatouer.enqueue(client);
		placesOccupees++;
	}
	else
	{

	}
	mutex1.unlock();
}
