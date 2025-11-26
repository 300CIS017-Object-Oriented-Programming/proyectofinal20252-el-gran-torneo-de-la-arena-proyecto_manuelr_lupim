#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_GUERRERO_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_GUERRERO_H

#include "Personaje.h"

class Guerrero : public Personaje {
private:
    float probabilidadCritico;

public:
    Guerrero(string n, int nv, int v, int a, int d);
    void realizarAccion(Personaje* objetivo) override;
};


#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_GUERRERO_H