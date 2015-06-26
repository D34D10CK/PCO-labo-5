#include "barbier.h"

Barbier::Barbier(SalleAttente* salle) : salle(salle)
{

}

Barbier::~Barbier()
{

}

void Barbier::run() {
    std::cout << "Barbier is running." << std::endl;

    forever
    {
        salle->traiterClient();
    }
}
