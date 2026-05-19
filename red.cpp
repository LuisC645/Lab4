#include "Red.h"

void Red::agregarRouter(string nombre) {

    // Existe?
    if (routers.find(nombre) == routers.end()) {
        routers.insert({nombre, Router(nombre)});
    }
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

    for (map<string,int>::iterator it = distancias.begin(); it != distancias.end(); it++){
        routers[origen].agregarCosto(it->first, it->second);
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

void Red::recalcularTablas() {

    for (map<string, Router>::iterator it = routers.begin(); it != routers.end();  it++){
        it->second.limpiarTabla();
    }

    for (map<string, Router>::iterator it1 = routers.begin(); it1 != routers.end(); it1++){

        string origen = it1->first;

        for (map<string, Router>::iterator it2 = routers.begin(); it2 != routers.end(); it2++){

            string destino = it2->first;

            // Evitar calcular hacia si mismo
            if (origen != destino) {
                encontrarCamino(origen, destino);
            }
        }
    }
}

void Red::showTablas() {

    for (map<string, Router>::iterator it = routers.begin(); it != routers.end(); it++){
        it->second.showTablaCostos();
        cout << endl;
    }
}

void Red::eliminarEnlace(string origen,
                         string destino) {

    // Existe?
    if (routers.find(origen) == routers.end() || routers.find(destino) == routers.end()){
        cout << "Router no encontrado." << endl;
        return;
    }

    // Eliminar conexiones
    routers[origen].eliminarVecino(destino);
    routers[destino].eliminarVecino(origen);

    // recalcularTablas();
    cout << "Enlace eliminado." << endl;
}

void Red::eliminarRouter(string nombre) {

    // Existe?
    if (routers.find(nombre) == routers.end()) {
        cout << "Router no existe." << endl;
        return;
    }

    // Eliminar referencias en vecinos
    for (map<string, Router>::iterator it = routers.begin(); it != routers.end(); it++){
        it->second.eliminarVecino(nombre);
    }

    // Eliminar router del map
    routers.erase(nombre);
    //recalcularTablas();

    cout << "Router eliminado." << endl;
}
