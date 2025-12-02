#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_TORNADO_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_TORNADO_H

#include "ObjetoMagico.h"

class Tornado : public ObjetoMagico {
public:
    Tornado(int stock); //ver cuantos hay disponibles
    void usar(Personaje* objetivo) override; //Sobrescribe el métod.o puro de ObjetoMagico (Aquí ocurrirá el ataque del tornado.)
};


#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_TORNADO_H