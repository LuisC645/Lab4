#include "red.h"

int main() {

    Red red;

    // Agregar routers
    red.agregarRouter("A");
    red.agregarRouter("B");
    red.agregarRouter("C");
    red.agregarRouter("D");

    // Conectar routers
    red.conectarRouters("A", "B", 4);
    red.conectarRouters("A", "D", 5);
    red.conectarRouters("A", "C", 10);

    red.conectarRouters("B", "C", 3);
    red.conectarRouters("B", "D", 1);

    red.conectarRouters("D", "C", 2);

    red.showRed();

    red.encontrarCamino("A", "C");

    return 0;
}
