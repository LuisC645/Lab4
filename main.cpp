#include "Red.h"

int main() {

    Red red;

    // Agregar routers
    red.agregarRouter("A");
    red.agregarRouter("B");
    red.agregarRouter("C");
    red.agregarRouter("D");

    // Conexiones
    red.conectarRouters("A", "B", 4);
    red.conectarRouters("A", "D", 5);
    red.conectarRouters("A", "C", 10);

    red.conectarRouters("B", "C", 3);
    red.conectarRouters("B", "D", 1);

    red.conectarRouters("D", "C", 2);

    // Topologia
    cout << "RED" << endl;

    red.showRed();

    // Calcular caminos
    // red.encontrarCamino("A", "C");
    // red.encontrarCamino("B", "D");
    // red.encontrarCamino("D", "A");

    red.recalcularTablas();

    // Mostrar tablas
    cout << endl;
    cout << "TABLAS" << endl;

    red.showTablas();

    return 0;
}
