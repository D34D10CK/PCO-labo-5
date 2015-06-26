#include "salleattente.h"
#include "client.h"
#include "acoiffer.h"
#include "atatouer.h"
#include <iostream>

SalleAttente::SalleAttente(int taille): nbSieges(taille) {}

SalleAttente::~SalleAttente() {}

// Un client à coiffer entre dans la salle d'attente
void SalleAttente::prendrePlace(ACoiffer* client)
{
    arriveeSalleMutex.lock();
	if (placesOccupees < nbSieges)
	{
		aCoiffer.enqueue(client);
		placesOccupees++;
        std::cout << "le client à coiffer" << client->getId() << " entre dans la salle d'attente." << std::endl;

        arriveeSalleMutex.unlock();
	}
	else
	{
        vaFaireUnTour.wait(&arriveeSalleMutex, (1000 * client->getTempsPousse()) / 2);
		std::cout << "le client " << client->getId() << " va faire un tour." << std::endl;
        arriveeSalleMutex.unlock();
		prendrePlace(client);
	}
}

// Un client à tatouer entre dans la salle d'attente
void SalleAttente::prendrePlace(ATatouer* client)
{
    arriveeSalleMutex.lock();
    if (placesOccupees < nbSieges)
    {
        aTatouer.enqueue(client);

        placesOccupees++;
        std::cout << "le client à tatouer " << client->getId() << " entre dans la salle d'attente." << std::endl;

        arriveeSalleMutex.unlock();
    }
    else
    {
        vaFaireUnTour.wait(&arriveeSalleMutex, (1000 * client->getTempsTatouage) / 2);
        std::cout << "le client " << client->getId() << " va faire un tour." << std::endl;
        arriveeSalleMutex.unlock();
        prendrePlace(client);
    }
    arriveeSalleMutex.unlock();
}

// Le client attend le barbier dans la salle
void SalleAttente::attendreBarbier(Client* client)
{
    // Si le barbier est occupé, on l'attend
    if (!isFree)
    {
        // tant que le client n'est pas le suivant, il attend
        while (client != next)
        {
           attendreBarbierMutex.lock();
           attendreBarbierCondition.wait(&attendreBarbierMutex);
           attendreBarbierMutex.unlock();
        }
    }
    // On signale au barbier qu'il y a des gens dans la salle d'attente
    else
    {
        salleVide.wakeOne();
    }

    // Le client est traité avec passion
    traitementEnCours.lock();
    enCoursDeTraitement.wait(&traitementEnCours);
    traitementEnCours.unlock();
}

// Le barbier tente de traiter un client
void SalleAttente::traiterClient() {
    // S'il y a des gens à tatouer
    if (aTatouer.length() > 0) {
        // on traite le client à tatouer
        traitementEnCours.lock();

        next = aTatouer.front();
        aTatouer.pop_front();

        std::cout << "Le barbier tatoue le client #" << next->getId() << "..." << std::endl;

        arriveeSalleMutex.lock();
        placesOccupees--;
        arriveeSalleMutex.unlock();

        // Traitement en cours
        sleep(rand() % 3 + 1);

        // Le client a été traité, on le réveille.
        enCoursDeTraitement.wakeOne();

        attendreBarbierCondition.wakeAll();
        traitementEnCours.unlock();
    }
    // Sinon, s'il y a des gens à coiffer
    else if (aCoiffer.length() > 0) {
        // on traite le client à coiffer
        traitementEnCours.lock();

        next = aCoiffer.front();
        aCoiffer.pop_front();

        std::cout << "Le barbier coiffe le client #" << next->getId() << "..." << std::endl;

        arriveeSalleMutex.lock();
        placesOccupees--;
        arriveeSalleMutex.unlock();

        // Traitement en cours
        sleep(rand() % 3 + 1);

        // Le client a été traité, on le réveille.
        enCoursDeTraitement.wakeOne();

        attendreBarbierCondition.wakeAll();
        traitementEnCours.unlock();
    }
    // Sinon, on dort
    else {
        // le barbier peut dormir
        std::cout << "Le barbier s'endort..." << std::endl;
        isFree = true;
        salleVideMutex.lock();
        salleVide.wait(&salleVideMutex);
        salleVideMutex.unlock();
        isFree = false;
        std::cout << "Le barbier se réveille..." << std::endl;
    }
}
