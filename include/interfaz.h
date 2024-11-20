#ifndef __INTERFAZ_H_
#define __INTERFAZ_H_

#include "documento.h"


void imprimirMenuPrincipal();
void imprimirEnCuadro(std::string mensaje);

// Opciones del menu principal
void menuLeerArchivo(Documento **doc, std::string &ruta);
void menuGuardarArchivo(Documento *doc, std::string nombreArchivo);
void menuGuardarArchivoComo(Documento *doc);
void menuLineas(Documento **doc);
void menuPalabras(Documento **doc);

// Opciones del submenus de lineas
Linea *submenuCrearLinea();
void submenuInsertarLinea(Documento **doc, Linea *linea);
void submenuMoverLinea(Documento **doc);
void submenuEliminarLinea(Documento **doc);

// Opciones del submenus de palabras
void submenuBuscarPalabra(Documento *doc);
void submenuEliminarPalabra(Documento **doc);
void submenuModificarPalabra(Documento **doc);
void submenuSustituirPalabra(Documento **doc);


bool preguntarSiNo();
int pedirEntero(const std::string &pregunta);


#endif
