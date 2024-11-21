#include "linea.h"
#include <iostream>


bool lineaVacia(Linea *linea) {
    return linea == nullptr;
}


// TODO: Implementar insertarPalabra
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


// Reemplaza todas las instancias de una palabra por otra en una línea
void sustituirPalabra(Linea **linea, std::string palabra, std::string reemplazo) {
    Linea *l = *linea;

    while (l) {
        if (l->palabra == palabra)
            l->palabra = reemplazo;

        l = l->prox;
    }
}


// Elimina la primera instancia de una palabra de una linea
void eliminarPalabraPorValor(Linea **linea, std::string palabra) {
    if (lineaVacia(*linea))
        return;

    Linea *l = *linea;

    if ((*linea)->palabra == palabra) {
        *linea = l->prox;
        delete l;
        return;
    }

    while (l->prox) {
        if (l->prox->palabra == palabra) {
            Linea *aux = l->prox;
            l->prox = aux->prox;
            delete aux;
            return;
        }

        l = l->prox;
    }
}


// Elimina una palabra de una linea en base a su posición
void eliminarPalabraPorIndice(Linea **linea, int n) {
    if (lineaVacia(*linea) || n < 0)
        return;

    Linea *l = *linea;

    if (n == 0) {
        *linea = l->prox;
        delete l;
        return;
    }

    while (l->prox && n --> 1) l = l->prox;

    if (l->prox) {
        Linea *aux = l->prox;
        l->prox = aux->prox;
        delete aux;
    }
}


void vaciarLinea(Linea **linea) {
    Linea *l = *linea;

    while (l) {
        *linea = l->prox;
        delete l;
        l = *linea;
    }
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

