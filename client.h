#ifndef CLIENT_H
#define CLIENT_H

#include "salleattente.h"
#include <QThread>

class Client : public QThread
{
private:
	SalleAttente* salle;
    int id;

public:
	Client(SalleAttente*);
	~Client();
	int getId();
};

#endif // CLIENT_H
