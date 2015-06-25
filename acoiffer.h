#ifndef ACOIFFER_H
#define ACOIFFER_H

#include "client.h"
#include "salleattente.h"

class SalleAttente;

class ACoiffer
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
