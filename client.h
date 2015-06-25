#ifndef CLIENT_H
#define CLIENT_H

class SalleAttente;

#include <QThread>

class Client : public QThread
{
private:
    int id;
    static int globalId;

protected:
    SalleAttente* salle;

public:
	Client(SalleAttente*);
	~Client();
	int getId();
};

#endif // CLIENT_H
