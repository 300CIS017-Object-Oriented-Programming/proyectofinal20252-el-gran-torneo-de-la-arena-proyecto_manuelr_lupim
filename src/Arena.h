#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_ARENA_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_ARENA_H

#include <vector>

class Personaje;

class Arena {
public:
    void cargarEquipos(const std::vector<Personaje*> &a, const std::vector<Personaje*> &b);
    void iniciar();

private:
    std::vector<Personaje*> eq1;
    std::vector<Personaje*> eq2;

    bool vivos(const std::vector<Personaje*> &v);
};



#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_ARENA_H