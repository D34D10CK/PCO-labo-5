#ifndef BARBIER_H
#define BARBIER_H

#include <QQueue>
#include <QThread>
#include "client.h"
#include "salleattente.h"

class Barbier : public QThread
{
private:
    QQueue<Client*> aCoiffer;
    QQueue<Client*> aTatouer;
    SalleAttente* salle;
	
public:
    Barbier(SalleAttente *salle);
	~Barbier();
    void run();
};

#endif // BARBIER_H
