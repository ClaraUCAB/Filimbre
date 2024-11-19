#ifndef __INTERFAZ_H_
#define __INTERFAZ_H_

#include "documento.h"


void imprimirMenuPrincipal();
void imprimirEnCuadro(std::string mensaje);

// Opciones del menu principal
void menuLeerArchivo(Documento **doc);
void menuGuardarArchivo(Documento *doc, std::string nombreArchivo);
void menuGuardarArchivoComo(Documento *doc);
void menuLineas(Documento *doc);
void menuPalabras();

// Opciones del submenus de lineas
Linea *submenuCrearLinea();
void submenuInsertarLinea(Documento *doc, Linea *linea);
void submenuMoverLinea(Linea *linea, int i, int j);
void submenuEliminarLinea(Linea *linea, int i);

// Opciones del submenus de palabras
void submenuBuscarPalabra(Documento *doc, std::string palabra);
// void submenuEliminarPalabra(Linea *linea, std::string);
// void submenuModificarPalabra(Linea *linea);
// void submenuSustituirPalabra(Linea *linea);


bool preguntarSiNo();
int pedirEntero(const std::string &pregunta);


#endif
