#include "client.h"

int Client::globalId = 0;

Client::Client(SalleAttente* salle): salle(salle)
{
	id = globalId++;
}

Client::~Client() {}

int Client::getId()
{
	return id;
}
