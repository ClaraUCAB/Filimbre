#ifndef __LINEA_H_
#define __LINEA_H_

#include <string>


struct Linea {
    std::string palabra;
    Linea *prox;
};


bool lineaVacia(Linea *linea);

void insertarPalabra(Linea **linea, std::string palabra, int n);
void apendarPalabra(Linea **linea, std::string palabra);

void imprimirLinea(Linea *linea);
void imprimirLineaNumerada(Linea *linea, int n, int m);


#endif  // __LINEA_H_
