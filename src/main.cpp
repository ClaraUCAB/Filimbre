#include "documento.h"
#include "utils.h"
#include "interfaz.h"

#include <iostream>


int main() {
    std::string entrada;
    std::string rutaArchivo;
    Documento *doc = nullptr;
    int opcion;

    clear();

    do {
        imprimirMenuPrincipal();
        opcion = pedirEntero(">>> ");

        clear();

        switch (opcion) {
            case 0:
                std::cout << "Gracias por usar Filimbre Text Editor. Bye bye!" << std::endl;
                pause();
                return 0;
                break;

            case 1:
                // leer el documento y si no existe abre uno en blanco.
                menuLeerArchivo(&doc);
                pause();
                break;

            case 2:
                if (!doc) {
                    std::cout << "Por favor cargue un archivo primero." << std::endl;
                } else {
                    imprimirDocumento(doc);
                }
                pause();
                break;

            case 3:
                menuGuardarArchivo(doc, rutaArchivo);
                pause();
                break;

            case 4:
                menuGuardarArchivoComo(doc);
                pause();
                break;

            case 5:  
                menuLineas(doc);
                break;

            case 6:
                clear();
                menuPalabras();
                opcion = pedirEntero("");
                while (opcion != 0){
                    switch (opcion){
                        case 1:
                            clear();
                            break;

                        case 2:
                            clear();
                            break;

                        case 3:
                            clear();
                            break;

                        case 4:
                            clear();
                            break;

                        default:
                            clear();
                            imprimirEnCuadro("Ingrese una opción válida");
                            break;
                    }
                }


                break;

            default:
                clear();
                imprimirEnCuadro("Ingrese una opción válida");
                break;
        }
    } 
    while (opcion != 0);
}

