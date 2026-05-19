#ifndef ROUTER_H
#define ROUTER_H

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Router {

private:

    string nombre;
    vector<pair<string,int>> vecinos;
    map<string,int> tablaCostos;

public:

    Router();
    Router(string nombre);

    void addVecino(string vecino, int costo);
    void agregarCosto(string destino, int costo);
    void showVecinos();
    void showTablaCostos();

    // Getters
    string getNombre();
    vector<pair<string,int>> getVecinos();
    map<string,int> getTablaCostos();
};

#endif
