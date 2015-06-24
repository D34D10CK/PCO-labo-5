#ifndef ACOIFFER_H
#define ACOIFFER_H

#include "client.h"

class ACoiffer : Client
{
private:
	int tempsDePousseDesCheveux;

public:
    ACoiffer(SalleAttente*);
    ~ACoiffer();
    void run();
};

#endif // ACOIFFER_H
