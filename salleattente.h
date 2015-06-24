#ifndef SALLEATTENTE_H
#define SALLEATTENTE_H
#include "client.h"

class SalleAttente : public QThread
{
private:
	QMutex mutex;
	QQueue<ACoiffer*> aCoiffer;
	QQueue<ATatouer*> aTatouer;
	int nbSieges;
	int placesOccupees;

public:
	SalleAttente();
	~SalleAttente();
	void prendrePlace(ACoiffer*);
	void prendrePlace(ATatouer*);
};

#endif // SALLEATTENTE_H
