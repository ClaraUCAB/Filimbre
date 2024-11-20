#include "utils.h"
#include <iostream>
#include <limits>

// Devuelve la cantidad de dígitos que tiene un número
int digitos(int n) {
    int d = 1;
    while ((n = n / 10) > 0) d++;
    return d;
}

// Limpia la consola independientemente del OS
void clear() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Pausa la ejecución de programa independientemente del OS
void pause() {
    std::cin.clear();

    std::cout << "\nPresione la tecla ENTER para continuar...";
    std::cin.get();
}

