#ifndef CLIENT_H
#define CLIENT_H

class Client : public QThread
{
private:
	SalleAttente* salle;

public:
	Client(SalleAttente*);
	~Client();
};

#endif // CLIENT_H
