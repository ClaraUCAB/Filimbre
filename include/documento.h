#ifndef __DOCUMENTO_H_
#define __DOCUMENTO_H_

#include "linea.h"
#include "listas.h"


struct Documento {
    Linea *linea;
    Documento *prox;
};


bool documentoVacio(Documento *doc);
int contarLineas(Documento *doc);

void insertarLinea(Documento **doc, Linea *linea, int n);
void apendarLinea(Documento **doc, Linea *linea);

void eliminarLinea(Documento **doc, Linea *linea);
void eliminarLineaPorIndice(Documento **doc, int n);

void moverLineaPorIndice(Documento **doc, int i, int j);

Lista *buscarPalabraEnDocumento(Documento *doc, std::string);
Linea *buscarLineaPorIndice(Documento *doc, int i);

Documento *leerDocumento(std::string ruta);
void escribirDocumento(Documento *doc, std::string ruta);

void imprimirDocumento(Documento *doc);


#endif  // __DOCUMENTO_H_
