#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_GUILD_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_GUILD_H

#include <string>
#include <vector>
#include <unordered_map>
#include "Personaje.h"
#include "ObjetoMagico.h"

using  std::unordered_map;
using std::vector;

class Guild {
private:
    string nombreGuild;
    unordered_map<string, Personaje*> heroes;
    vector<ObjetoMagico*> inventario;
    int contadorId;

public:
    Guild(string nombre);
    ~Guild();

    void inicializarHeroes();
    void agregarHeroe(Personaje* heroe);
    void eliminarHeroe(string nombre);
    Personaje* buscarHeroe(string nombre);
    void listarHeroes() const;

    void agregarObjeto(ObjetoMagico* objeto);
    void listarInventario() const;
    vector<Personaje*> getHeroesVivos() const;
    vector<ObjetoMagico*>& getInventario();

    string getNombre() const;
    // Guardar / cargar heroes en JSON
    void guardarHeroesJSON(const std::string& filename) const;
    void cargarHeroesDesdeJSON(const std::string& filename);

};


#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_GUILD_H