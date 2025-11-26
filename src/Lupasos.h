#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_LUPASOS_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_LUPASOS_H

#include "Personaje.h"

class Lupasos : public Personaje {
private:
    bool formaLobo;
    int contadorAtaques;

public:
    Lupasos(string n, int nv, int v, int a, int d);
    void realizarAccion(Personaje* objetivo) override;
    void transformar();
    void volverHumano();
};


#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_LUPASOS_H