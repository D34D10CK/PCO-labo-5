#ifndef SALLEATTENTE_H
#define SALLEATTENTE_H

class ACoiffer;
class ATatouer;
class Client;

#include <QMutex>
#include <QThread>
#include <QWaitCondition>
#include <QQueue>

class SalleAttente : public QThread
{
private:
    QMutex arriveeSalleMutex;
    QMutex traitementEnCours;
    QMutex attendreBarbierMutex;
    QMutex salleVideMutex;
    QMutex isFreeMutex;

    QWaitCondition vaFaireUnTour;
    QWaitCondition attendreBarbierCondition;
    QWaitCondition salleVide;
    QWaitCondition enCoursDeTraitement;

	QQueue<ACoiffer*> aCoiffer;
	QQueue<ATatouer*> aTatouer;

    Client* next;

    int nbSieges;
    int placesOccupees = 0;

    bool isFree = true;

public:
    SalleAttente(int taille);
    ~SalleAttente();
	void prendrePlace(ACoiffer*);
	void prendrePlace(ATatouer*);
    void attendreBarbier(Client*);
    void traiterClient();
};

#endif // SALLEATTENTE_H
