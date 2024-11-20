#include "documento.h"
#include "utils.h"
#include "interfaz.h"

#include <iostream>


int main() {
    Documento *doc = nullptr;
    std::string rutaArchivo;
    int opcion;

    clear();

    do {
        imprimirMenuPrincipal();
        opcion = pedirEntero(">>> ");

        clear();

        switch (opcion) {
            // Salir
            case 0:
                std::cout << "Gracias por usar Filimbre Text Editor. Bye bye!" << std::endl;
                pause();
                return 0;

            // Leer archivo
            case 1:
                menuLeerArchivo(&doc, rutaArchivo);
                pause();
                clear();
                break;

            // TODO: Cada 25 lineas tiene que haber una pausa
            // Imprimir archivo
            case 2:
                if (!doc) {
                    std::cout << "Por favor cargue un archivo primero." << std::endl;
                } else {
                    imprimirDocumento(doc);
                }
                pause();
                clear();
                break;

            // Guardar archivo
            case 3:
                menuGuardarArchivo(doc, rutaArchivo);
                pause();
                clear();
                break;

            // Guardar como
            case 4:
                menuGuardarArchivoComo(doc);
                pause();
                clear();
                break;

            // Lineas
            case 5:  
                menuLineas(&doc);
                clear();
                break;

            // Palabras
            case 6:
                menuPalabras(&doc);
                clear();
                break;

            default:
                clear();
                imprimirEnCuadro("Ingrese una opción válida");
                break;
        }
    } 
    while (opcion != 0);
}

