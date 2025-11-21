#ifndef PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_INVENTARIO_H
#define PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_INVENTARIO_H


#include <unordered_map>
#include <string>

class Personaje;

class Inventario {
public:
    void agregarTipo(const std::string &nombre, int cantidad);
    bool asignar(Personaje *p, const std::string &tipo);
    void mostrar() const;

private:
    std::unordered_map<std::string,int> stock;
};

#endif //PROYECTOFINAL20252_EL_GRAN_TORNEO_DE_LA_ARENA_PROYECTO_MANUELR_LUPIM_INVENTARIO_H