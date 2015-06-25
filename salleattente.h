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
	QMutex mutex1;
	QMutex mutex2;
    QMutex salleVideMutex;

    QWaitCondition vaFaireUnTour;
    QWaitCondition attendreBarbierCondition;
    QWaitCondition salleVide;

	QQueue<ACoiffer*> aCoiffer;
	QQueue<ATatouer*> aTatouer;

    Client* next;

    int nbSieges;
	int placesOccupees;

public:
    SalleAttente(int taille);
	~SalleAttente();
	void prendrePlace(ACoiffer*);
	void prendrePlace(ATatouer*);
    void attendreBarbier(Client*);
    void traiterClient();
};

#endif // SALLEATTENTE_H
