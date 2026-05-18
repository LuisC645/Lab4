#include "router.h"

Router::Router() {

}

Router::Router(string nombre) {
    this->nombre = nombre;
}

void Router::addVecino(string vecino, int costo) {
    vecinos.push_back({vecino, costo});
}

string Router::getNombre() {
    return nombre;
}

vector<pair<string,int>> Router::getVecinos() {
    return vecinos;
}

void Router::showVecinos() {

    cout << "Router " << nombre << endl;

    for (int i = 0; i < vecinos.size(); i++) {
        cout << "Vecino: " << vecinos[i].first << " | Costo: " << vecinos[i].second << endl;
    }
}
