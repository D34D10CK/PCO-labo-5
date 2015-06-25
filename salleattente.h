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
	QWaitCondition vaFaireUnTour;
    QWaitCondition attendreBarbierCondition;
	QQueue<ACoiffer*> aCoiffer;
	QQueue<ATatouer*> aTatouer;
	int nbSieges;
	int placesOccupees;

public:
    SalleAttente(int taille);
	~SalleAttente();
	void prendrePlace(ACoiffer*);
	void prendrePlace(ATatouer*);
	void attendreBarbier(Client*);
};

#endif // SALLEATTENTE_H
