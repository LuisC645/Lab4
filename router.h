#ifndef ROUTER_H
#define ROUTER_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Router {
private:

    string nombre;
    vector<pair<string,int>> vecinos;

public:

    Router();

    // Constructor
    Router(string nombre);

    // Getters
    string getNombre();
    vector<pair<string,int>> getVecinos();

    // Funciones
    void addVecino(string vecino, int costo);
    void showVecinos();

};

#endif
