#ifndef ATATOUER_H
#define ATATOUER_H

#include "salleattente.h"
#include "client.h"

class ATatouer : public Client
{
public:
    ATatouer(SalleAttente* salle);
	~ATatouer();
	void run();
};

#endif // ATATOUER_H
