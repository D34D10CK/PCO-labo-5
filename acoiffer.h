#ifndef ACOIFFER_H
#define ACOIFFER_H

class SalleAttente;

#include "client.h"
#include "salleattente.h"

class ACoiffer : public Client
{
private:
	int tempsDePousseDesCheveux;

public:
    ACoiffer(SalleAttente* salle);
    ~ACoiffer();
    void run();
    int getTempsPousse();
};

#endif // ACOIFFER_H
