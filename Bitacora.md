classDiagram
%% Clase base simple
class Personaje {
- string: id
- string: nombre
- int: vida
- int: ataque
- int: defensa
- string: rol
+ Personaje(id,nombre,vida,ataque,defensa,rol)
+ atacar(Personaje* objetivo)
+ recibirDanio(int cantidad)
+ asignarObjeto(Item* obj) : bool
}

    %% Subclases (sin atributos extra por ahora)
    Personaje <|-- Guerrero
    Personaje <|-- Mago
    Personaje <|-- Sanador

    class Item {
      - string: id
      - string: nombre
      - int: stock
      + aplicar(Personaje* usuario, Personaje* objetivo) : bool
    }

    class Inventario {
      - map<string, Item*>: int
      + agregarItem(Item* item)
      + obtenerItem(string id) : Item*
      + asignarA(Personaje* p, string itemId) : bool
    }

    class Guild {
      - map<string, Personaje*>: heroes 
      + agregarHeroe(Personaje* p)
      + obtenerHeroe(string id) : Personaje*
      + listarHeroes()
    }

    %% relaciones
    Guild "1" o-- "*" Personaje : contiene
    Inventario "1" o-- "*" Item : almacena
    Personaje "1" --> "0..2" Item : puede llevar