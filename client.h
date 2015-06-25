#ifndef CLIENT_H
#define CLIENT_H

class Client : public QThread
{
private:
	SalleAttente* salle;
	private int id;

public:
	Client(SalleAttente*);
	~Client();
	int getId();
};

#endif // CLIENT_H
