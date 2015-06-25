#ifndef ATATOUER_H
#define ATATOUER_H

class SalleAttente;

#include "salleattente.h"
#include "client.h"

class ATatouer : public Client
{
private:
	int tempsAvantTatouage;
	
public:
    ATatouer(SalleAttente* salle);
	~ATatouer();
	void run();
};

#endif // ATATOUER_H
