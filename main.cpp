#include "red.h"

int main() {

    Red red;

    // Agregar routers
    red.addRouter("A");
    red.addRouter("B");
    red.addRouter("C");
    red.addRouter("D");

    // Conectar routers
    red.conectarRouters("A", "B", 4);
    red.conectarRouters("A", "D", 5);
    red.conectarRouters("A", "C", 10);

    red.conectarRouters("B", "C", 3);
    red.conectarRouters("B", "D", 1);

    red.conectarRouters("D", "C", 2);

    red.showRed();

    return 0;
}
