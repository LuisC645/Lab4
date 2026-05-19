#include "utils.h"

void cargarRed(string archivo, Red& red) {

    ifstream file(archivo);

    if (!file.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    string origen;
    string destino;
    int costo;

    while (file >> origen >> destino >> costo) {

        red.agregarRouter(origen);
        red.agregarRouter(destino);
        red.conectarRouters(origen, destino, costo);
    }

    file.close();

    cout << "Red cargada correctamente." << endl;
}
