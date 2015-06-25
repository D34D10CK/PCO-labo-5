#ifndef BARBIER_H
#define BARBIER_H

#include <QQueue>
#include "client.h"

class Barbier
{
private:
    QQueue<Client*> aCoiffer;
    QQueue<Client*> aTatouer;
	
public:
	Barbier();
	~Barbier();
};

#endif // BARBIER_H
