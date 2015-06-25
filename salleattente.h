#ifndef SALLEATTENTE_H
#define SALLEATTENTE_H
#include "client.h"

class SalleAttente : public QThread
{
private:
	QMutex mutex1;
	QMutex mutex2;
	QWaitCondition vaFaireUnTour;
	QWaitCondition attendreBarbier;
	QQueue<ACoiffer*> aCoiffer;
	QQueue<ATatouer*> aTatouer;
	int nbSieges;
	int placesOccupees;

public:
	SalleAttente();
	~SalleAttente();
	void prendrePlace(ACoiffer*);
	void prendrePlace(ATatouer*);
	void attendreBarbier(Client*);
};

#endif // SALLEATTENTE_H
