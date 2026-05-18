#include "red.h"

void Red::addRouter(string nombre) {
    routers.insert({nombre, Router(nombre)});
}

void Red::conectarRouters(string origen, string destino, int costo) {
    routers[origen].addVecino(destino, costo);
    routers[destino].addVecino(origen, costo);
}

void Red::showRed() {

    for (auto r : routers) {
        r.second.showVecinos();
        cout << endl;
    }
}
