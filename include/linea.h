#ifndef __LINEA_H_
#define __LINEA_H_

#include <string>
#include "listas.h"


struct Linea {
    std::string palabra;
    Linea *prox;
};


bool lineaVacia(Linea *linea);

void insertarPalabra(Linea **linea, std::string palabra, int n);
void apendarPalabra(Linea **linea, std::string palabra);

bool existePalabra(Linea *linea, std::string palabra);

void sustituirPalabra(
        Linea **linea,
        std::string palabra,
        std::string reemplazo
);

void eliminarPalabraPorValor(Linea **linea, std::string palabra);
void eliminarPalabraPorIndice(Linea **linea, int n);
void vaciarLinea(Linea **linea);

void imprimirLinea(Linea *linea);
void imprimirLineaNumerada(Linea *linea, int n, int m);


#endif  // __LINEA_H_
