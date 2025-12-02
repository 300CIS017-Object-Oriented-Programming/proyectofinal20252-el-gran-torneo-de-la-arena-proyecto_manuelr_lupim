#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_GUILD_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_GUILD_H

#include <string>
#include <vector>
#include <unordered_map>
#include "Personaje.h"
#include "ObjetoMagico.h"

using  std::unordered_map; //diccionario (listas de listas, teniendo clave y valor)
                            // todas las cosas que tiene
using std::vector;

class Guild {
private:
    string nombreGuild;
    unordered_map<string, Personaje*> heroes;   // heroes: mapa nombre → Personaje*. Clave: el nombre del héroe (importante: nombres únicos).
    vector<ObjetoMagico*> inventario;
    int contadorId;

public:
    Guild(string nombre);
    ~Guild();

    void inicializarHeroes();               //crear los heroes
    void agregarHeroe(Personaje* heroe);    // añade los personajes* al mapa
    void eliminarHeroe(string nombre);
    Personaje* buscarHeroe(string nombre);
    void listarHeroes() const;              //imprime info de cada héroe

    void agregarObjeto(ObjetoMagico* objeto);   //lo añada al inventario
    void listarInventario() const;
    vector<Personaje*> getHeroesVivos() const; //vector con punteros a héroes que estaVivo() == true.
    vector<ObjetoMagico*>& getInventario();
    string getNombre() const;



    // Guardar / cargar heroes en JSON
    void guardarHeroesJSON(const std::string& filename) const; //Métodos para persistencia con JSON
    void cargarHeroesDesdeJSON(const std::string& filename);

};


#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_GUILD_H

