#ifndef CLIENT_H
#define CLIENT_H

class Client : public QThread
{
private:
	int priority;
	SalleAttente* salle;

public:
	Client(int, SalleAttente*);
	~Client();
	int getPriority() const;
};

#endif // CLIENT_H
