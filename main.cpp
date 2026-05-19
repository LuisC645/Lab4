#include "Red.h"
#include "utils.h"

int main() {

    Red red;

    cargarRed("data/red.txt", red);

    red.showRed();

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

    cout << "\nEliminar enlace" << endl;

    red.eliminarEnlace("A","B");

    red.recalcularTablas();

    // Mostrar tablas
    cout << endl;
    cout << "TABLAS" << endl;

    red.showTablas();

    cout << "\nEliminar router" << endl;

    red.eliminarRouter("A");

    red.recalcularTablas();

    // Mostrar tablas
    cout << endl;
    cout << "TABLAS" << endl;

    red.showTablas();


    return 0;
}
