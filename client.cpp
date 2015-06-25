#include "client.h"

Client::Client(SalleAttente* salle): salle(salle)
{
	id = globalId++;
}

Client::~Client() {}

int Client::getId()
{
	return id;
}

static int Client::globalId = 0;