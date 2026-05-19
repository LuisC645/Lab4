#include "Router.h"

Router::Router() {

}

Router::Router(string nombre) {
    this->nombre = nombre;
}

void Router::addVecino(string vecino, int costo) {
    vecinos.push_back({vecino, costo});
}

void Router::agregarCosto(string destino, int costo) {
    tablaCostos[destino] = costo;
}

string Router::getNombre() {
    return nombre;
}

vector<pair<string,int>> Router::getVecinos() {
    return vecinos;
}

map<string,int> Router::getTablaCostos() {
    return tablaCostos;
}

void Router::showVecinos() {

    cout << "Router " << nombre << endl;

    for (int i = 0; i < vecinos.size(); i++) {
        cout << "Vecino: " << vecinos[i].first << " | Costo: " << vecinos[i].second << endl;
    }
}

void Router::showTablaCostos() {

    cout << endl << "Tabla de costos de " << nombre << endl;

    for (map<string,int>::iterator it = tablaCostos.begin(); it != tablaCostos.end(); it++){
        cout << "Destino: " << it->first << " | Costo: " << it->second << endl;
    }
}

void Router::eliminarVecino(string vecino) {

    for (int i = 0; i < vecinos.size(); i++) {

        if (vecinos[i].first == vecino) {
            vecinos.erase(vecinos.begin() + i);
            break;
        }
    }
}

void Router::limpiarTabla() {

    tablaCostos.clear();
}
