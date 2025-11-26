#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_BERSERKER_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_BERSERKER_H

#include "Personaje.h"

class Berserker : public Personaje {
private:
    bool modoFuria;
    int turnosEnFuria;

public:
    Berserker(string n, int nv, int v, int a, int d);
    void realizarAccion(Personaje* objetivo) override;
    void activarFuria();
    void desactivarFuria();
};


#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_BERSERKER_H