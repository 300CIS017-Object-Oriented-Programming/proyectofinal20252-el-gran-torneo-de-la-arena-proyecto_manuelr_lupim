#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_ARENA_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_ARENA_H

#include "Guild.h"
#include <vector>
using std::vector;
using std::string;

class Arena {
private:
    Guild* guildJugador;
    vector<Personaje*> oponentes;
    int turnoActual;
    int objetosUsados;

public:
    Arena(Guild* guild);
    ~Arena();

    void inicializarOponentes();
    void iniciarCombate();
    bool equipoEliminado(const vector<Personaje*>& equipo) const;
    void mostrarResumen(const string& ganador) const;
};



#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_ARENA_H