#include "documento.h"
#include "utils.h"
#include "interfaz.h"

#include <iostream>


int main() {
    std::string entrada;
    std::string rutaArchivo;
    Documento *doc = nullptr;
    Lista *lineaNueva = nullptr;
    int opcion;

    do {
        imprimirMenuPrincipal();
        opcion = pedirEntero(">>> ");

        switch (opcion) {
            case 0:
                std::cout << "Gracias por usar Filimbre Text Editor. Bye bye!" << std::endl;
                pause();
                return 0;
                break;

            case 1:
                // leer el documento y si no existe abre uno en blanco.
                clear();
                if (doc != nullptr){
                    std::cout << "se va a borrar el archivo en RAM, quiere continuar? [si/no]: \n";
                    if(preguntarSiNo()){
                        std::cout << "indique el nombre del archivo: \n";
                        std::getline(std::cin, entrada);
                        doc = leerDocumento(("./../"+entrada));
                        std::getline(std::cin, entrada);
                    }
                    else{
                        break;
                    }
                }
                else{
                    std::cout << "indique el nombre del archivo: \n";
                    std::getline(std::cin, entrada);
                    doc = leerDocumento(("./../"+entrada));
                    std::getline(std::cin, entrada);
                    break;
                }
                break;

            case 2:
                clear();
                imprimirDocumento(doc);
                pause();
                break;

            case 3:
                clear();
                menuGuardarArchivo(doc, rutaArchivo);
                break;

            case 4:
                clear();
                menuGuardarArchivoComo(doc);
                break;

            case 5:  
                clear();
                menuLineas();
                opcion = pedirEntero("");
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

                    case 0:
                        clear();
                        break;

                    default:
                        clear();
                        std::cout << " ___________________________\n";
                        std::cout << "| Ingrese una opcion valida |\n";
                        std::cout << " ___________________________\n";
                        break;
                }
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
                            std::cout << " ___________________________\n";
                            std::cout << "| Ingrese una opcion valida |\n";
                            std::cout << " ___________________________\n";
                            break;
                    }
                }


                break;

            default:
                clear();
                std::cout << " ___________________________\n";
                std::cout << "| Ingrese una opcion valida |\n";
                std::cout << " ___________________________\n";
                break;
        }
    } 
    while (opcion != 0);
}

