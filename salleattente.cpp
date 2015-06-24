#include "salleattente.h"

SalleAttente::SalleAttente(int taille): nbSieges(taille) {}

SalleAttente::~SalleAttente() {}

void prendrePlace(ACoiffer* client)
{
	mutex.lock();
	if (placesOccupees < nbSieges)
	{
		aCoiffer.enqueue(client);
		placesOccupees++;
	}
	else
	{

	}
	mutex.unlock();
}

void prendrePlace(ATatouer* client)
{
	mutex.lock();
	if (placesOccupees < nbSieges)
	{
		aTatouer.enqueue(client);
		placesOccupees++;
	}
	else
	{

	}
	mutex.unlock();
}