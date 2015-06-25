#include "barbier.h"

Barbier::Barbier(SalleAttente* salle) : salle(salle)
{

}

Barbier::~Barbier()
{

}

void Barbier::run() {
    forever
    {
        salle->traiterClient();
    }
}
