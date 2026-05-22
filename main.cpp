#include "Red.h"
#include "utils.h"

int main() {

    Red red;

    cargarRed("data/red.txt", red);

    int opcion = 0;

    while(opcion != 9) {

        cout << endl;
        cout << "========== MENU ==========" << endl;

        cout << "1. Mostrar red" << endl;
        cout << "2. Mostrar tablas" << endl;
        cout << "3. Agregar router" << endl;
        cout << "4. Conectar routers" << endl;
        cout << "5. Eliminar router" << endl;
        cout << "6. Eliminar enlace" << endl;
        cout << "7. Encontrar camino" << endl;
        cout << "8. Recalcular tablas" << endl;
        cout << "9. Salir" << endl;

        cout << endl;
        cout << "Opcion: ";
        cin >> opcion;

        cout << endl;

        switch(opcion) {

        case 1: {
            cout << "===== RED =====" << endl;
            red.showRed();
            break;
        }

        case 2: {
            cout << "===== TABLAS =====" << endl;
            red.showTablas();
            break;
        }

        case 3: {
            string nombre;

            cout << "Nombre del router: ";
            cin >> nombre;
            red.agregarRouter(nombre);
            cout << "Router agregado." << endl;
            break;
        }

        case 4: {

            string origen;
            string destino;
            int costo;

            cout << "Origen: ";
            cin >> origen;

            cout << "Destino: ";
            cin >> destino;

            cout << "Costo: ";
            cin >> costo;

            red.conectarRouters(origen, destino, costo);
            red.recalcularTablas();

            cout << "Conexion agregada." << endl;
            break;
        }

        case 5: {

            string nombre;

            cout << "Router a eliminar: ";
            cin >> nombre;

            red.eliminarRouter(nombre);
            break;
        }

        case 6: {

            string origen;
            string destino;

            cout << "Origen: ";
            cin >> origen;

            cout << "Destino: ";
            cin >> destino;

            red.eliminarEnlace(origen, destino);
            break;
        }

        case 7: {

            string origen;
            string destino;

            cout << "Origen: ";
            cin >> origen;

            cout << "Destino: ";
            cin >> destino;

            red.encontrarCamino(origen, destino);
            break;
        }

        case 8: {

            red.recalcularTablas();

            cout << "Tablas recalculadas." << endl;
            break;
        }

        case 9: {

            cout << "Terminado gracias a lucho" << endl;
            break;
        }

        default:
            cout << "Opcion invalida." << endl;
        }
    }

    return 0;
}
