#include "client.h"

Client::Client(int priority, SalleAttente* salle)
	: priority(priority), salle(salle) {}

Client::~Client() {}

int Client::getPriority() const
{
	return priority;
}
