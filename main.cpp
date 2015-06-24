#include <QCoreApplication>
#include <iostream>
#include <limits.h>

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

	return a.exec();
}
