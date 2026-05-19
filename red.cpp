#include "Red.h"

void Red::agregarRouter(string nombre) {

    routers.insert({nombre, Router(nombre)});
}

void Red::conectarRouters(string origen, string destino, int costo){
    routers[origen].addVecino(destino, costo);
    routers[destino].addVecino(origen, costo);
}

void Red::showRed() {

    for (map<string, Router>::iterator it = routers.begin();
         it != routers.end();
         it++) {

        it->second.showVecinos();

        cout << endl;
    }
}

void Red::encontrarCamino(string origen, string destino){

    if (routers.find(origen) == routers.end()) {
        cout << "El router origen no existe" << endl;
        return;
    }

    if (routers.find(destino) == routers.end()) {
        cout << "El router destino no existe." << endl;
        return;
    }

    // Distancias minimas
    map<string, int> distancias;

    // Nodo anterior
    map<string, string> anteriores;

    // Nodos visitados
    set<string> visitados;

    // Cola de prioridad
    priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>> > cola;

    // Inicializar distancias en infinito
    for (map<string, Router>::iterator it = routers.begin();
         it != routers.end();
         it++) {

        distancias[it->first] = numeric_limits<int>::max();
    }

    // Distancia al origen
    distancias[origen] = 0;

    // Insertar origen en cola
    cola.push({0, origen});

    // Dijkstra
    while (!cola.empty()) {

        // Nodo con menor costo
        string actual = cola.top().second;

        cola.pop();

        // Evitar repetir nodos
        if (visitados.count(actual)) {
            continue;
        }

        visitados.insert(actual);

        // Obtener vecinos
        vector<pair<string,int>> vecinos =
            routers[actual].getVecinos();

        // Recorrer vecinos
        for (int i = 0; i < vecinos.size(); i++) {

            string vecino = vecinos[i].first;

            int costo = vecinos[i].second;

            int nuevaDistancia =
                distancias[actual] + costo;

            // Si encontramos mejor camino
            if (nuevaDistancia < distancias[vecino]) {

                distancias[vecino] = nuevaDistancia;

                anteriores[vecino] = actual;

                cola.push({nuevaDistancia, vecino});
            }
        }
    }

    if (distancias[destino] == numeric_limits<int>::max()) {
        cout << "No existe camino entre " << origen << " y " << destino << endl;
        return;
    }

    // Reconstruir camino
    vector<string> camino;
    string actual = destino;

    while (actual != origen) {
        camino.push_back(actual);
        actual = anteriores[actual];
    }

    camino.push_back(origen);

    // Mostrar camino
    cout << endl;
    cout << "Camino minimo: ";

    for (int i = camino.size() - 1; i >= 0; i--) {
        cout << camino[i];
        if (i != 0) {
            cout << " -> ";
        }
    }

    cout << endl;
    cout << "Costo total: " << distancias[destino] << endl;
}
