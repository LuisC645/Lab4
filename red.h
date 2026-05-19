#ifndef RED_H
#define RED_H

#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <limits>

#include "Router.h"

using namespace std;

class Red {

private:

    map<string, Router> routers;

public:

    void agregarRouter(string nombre);
    void conectarRouters(string origen, string destino, int costo);
    void showRed();
    void encontrarCamino(string origen, string destino);
    void showTablas();
    void recalcularTablas();
};

#endif
