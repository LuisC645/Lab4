#ifndef RED_H
#define RED_H

#include <iostream>
#include <map>
#include "router.h"

using namespace std;

class Red {

private:

    map<string, Router> routers;

public:

    void addRouter(string nombre);
    void conectarRouters(string origen, string destino, int costo);
    void showRed();
};

#endif
