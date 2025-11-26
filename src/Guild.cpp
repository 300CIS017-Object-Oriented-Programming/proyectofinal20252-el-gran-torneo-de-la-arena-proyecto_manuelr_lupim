#include "guild.h"
#include "Guild.h"
#include "Guerrero.h"
#include "Mago.h"
#include "Sanador.h"
#include "Berserker.h"
#include "Lupasos.h"
#include "PocionVida.h"
#include "AmuletoFuria.h"
#include "EscudoBendito.h"
#include "DanioElectrico.h"
#include "Tornado.h"
#include <iostream>
#include <fstream>
#include "DagaSombria.h"

Guild::Guild(string nombre) : nombreGuild(nombre), contadorId(1) {}

Guild::~Guild() {
    for (auto& par : heroes) {
        delete par.second;
    }
    for (ObjetoMagico* obj : inventario) {
        delete obj;
    }
}

void Guild::inicializarHeroes() {
    agregarHeroe(new Guerrero("Arthos", 5, 120, 25, 15));
    agregarHeroe(new Mago("Lyra", 5, 80, 30, 8));
    agregarHeroe(new Sanador("Elara", 5, 90, 15, 10));
    agregarHeroe(new Berserker("Ragnar", 5, 110, 28, 12));
    agregarHeroe(new Lupasos("Fenrir", 5, 100, 22, 13));

    agregarObjeto(new PocionVida(3));
    agregarObjeto(new AmuletoFuria(2));
    agregarObjeto(new EscudoBendito(2));
    agregarObjeto(new DanioElectrico(2));
    agregarObjeto(new Tornado(2));
    agregarObjeto(new DagaSombria(3));
}
