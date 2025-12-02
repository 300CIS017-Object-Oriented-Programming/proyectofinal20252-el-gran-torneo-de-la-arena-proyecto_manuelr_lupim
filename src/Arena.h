#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_ARENA_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_ARENA_H

#include "Guild.h" //recibe el puntero desde guild
#include <vector>
using std::vector;
using std::string;

class Arena {
private:
    Guild* guildJugador;
    vector<Personaje*> oponentes;   //los enemigos que se hacen en el momentico
    int turnoActual;
    int objetosUsados;

public:
    Arena(Guild* guild); // Recibe la Guild del jugador (se usan nuestros heroes) y la arena es responsable de liberar memoria de los oponentes creados por ella.
    ~Arena();

    void inicializarOponentes();
    void iniciarCombate();
    bool equipoEliminado(const vector<Personaje*>& equipo) const; //Devuelve true si todos los personajes están muertos.
    void mostrarResumen(const string& ganador) const;
};



#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_ARENA_H