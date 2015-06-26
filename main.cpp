#include <QCoreApplication>
#include <iostream>
#include <limits>
#include "barbier.cpp"
#include "client.cpp"
#include "acoiffer.cpp"
#include "atatouer.cpp"
#include "salleattente.cpp"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	int nbACoiffer;
	do {
		std::cout << "entrez le nombre de clients a coiffer:" << std::endl;
		std::cin >> nbACoiffer;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	while (nbACoiffer < 0);

	int nbATatouer;
	do {
		std::cout << "entrez le nombre de clients a tatouer:" << std::endl;
		std::cin >> nbATatouer;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	while (nbATatouer < 0);

	int tailleSalleAttente;
	do {
		std::cout << "entrez la taille (>0) de la salle d'attente:" << std::endl;
		std::cin >> tailleSalleAttente;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
    while (tailleSalleAttente < 1);

	std::vector<Client*> clients;
	SalleAttente salle(tailleSalleAttente);

    Barbier barbier(&salle);
    barbier.start();

	for (int i = 0; i < nbACoiffer; i++)
	{
		clients.push_back(new ACoiffer(&salle));
	}
	for (int i = 0; i < nbATatouer; i++)
	{
		clients.push_back(new ATatouer(&salle));
	}
	for (Client* c : clients)
	{
        c->start();
    }

	return a.exec();
}
