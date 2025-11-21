#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_GUILD_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_GUILD_H

#include <vector>

class Personaje;

class Guild {
public:
    ~Guild();
    void agregar(Personaje *p);
    void listar() const;
    Personaje* obtenerPorId(int id) const;
    std::vector<Personaje*>& getHeroes();

private:
    std::vector<Personaje*> heroes;
};


#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_GUILD_H