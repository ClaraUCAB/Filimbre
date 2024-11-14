#include "linea.h"
#include <iostream>


bool lineaVacia(Linea *linea) {
    return linea == nullptr;
}


void insertarPalabra(Linea **linea, std::string palabra, int n) {
    
}


void apendarPalabra(Linea **linea, std::string palabra) {
    Linea *nuevaLinea = new Linea;
    nuevaLinea->palabra = palabra;
    nuevaLinea->prox = nullptr;

    if (lineaVacia(*linea)) {
        *linea = nuevaLinea;
        return;
    }

    Linea *l = *linea;
    while (l->prox) l = l->prox;
    l->prox = nuevaLinea;
}


bool existePalabra(Linea *linea, std::string palabra) {
    Linea *l = linea;

    while (l) {
        if (l->palabra == palabra) return true;
        l = l->prox;
    }

    return false;
}


void imprimirLinea(Linea *linea) {
    if (!linea) {
        std::cout << std::endl;
        return;
    }

    Linea *l = linea;

    while (l->prox) {
        std::cout << l->palabra << " ";
        l = l->prox;
    }

    std::cout << l->palabra << std::endl;
}


void imprimirLineaNumerada(Linea *linea, int n, int m = 1) {
    std::string margen = "";
    while (m-- > 0) margen += " ";

    std::cout << n << margen << "┃ ";
    imprimirLinea(linea);
}

