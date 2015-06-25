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
    int getTempsPousse();
};

#endif // ACOIFFER_H
