#ifndef __INTERFAZ_H_
#define __INTERFAZ_H_

#include "documento.h"


void imprimirMenuPrincipal();

void menuLeerArchivo();
void menuGuardarArchivo(Documento *doc, std::string nombreArchivo);
void menuGuardarArchivoComo(Documento *doc);
void menuLineas();
void menuPalabras();


bool preguntarSiNo();
int pedirEntero(const std::string &pregunta);


#endif
