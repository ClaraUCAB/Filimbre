#ifndef __DOCUMENTO_H_
#define __DOCUMENTO_H_

#include "linea.h"
#include <fstream>

struct Documento {
    Linea *linea;
    Documento *prox;
};


bool documentoVacio(Documento *doc);
int contarLineas(Documento *doc);
//int digitos(int n);

void insertarLinea(Documento **doc, Linea *linea, int n);
void apendarLinea(Documento **doc, Linea *linea);

Documento *leerDocumento(std::string ruta);
void escribirDocumento(Documento *doc, std::string ruta);

void imprimirDocumento(Documento *doc);


#endif  // __DOCUMENTO_H_
