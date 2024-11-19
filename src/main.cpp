#include <iostream>
#include <string>
#include "linea.h"
#include "documento.h"
#include "utils.h"

void interfazMenuPrincipal()
{
    std::cout << "     ______    ____    __     ____    __  ___    ____     ____     ______ \n    / ____/   /  _/   / /    /  _/   /  |/  /   / __ )   / __ \   / ____/\n   / /_       / /    / /     / /    / /|_/ /   / __  |  / /_/ /  / __/   \n  / __/     _/ /    / /___ _/ /    / /  / /   / /_/ /  / _, _/  / /___   \n /_/       /___/   /_____//___/   /_/  /_/   /_____/  /_/ |_|  /_____/   \n";
    std::cout << "\n",
    std::cout << "Bienvenido al Editor de Texto Filimbre, escoja una opcion: \n";
    std::cout << "\n";
    std::cout << "1. Leer archivo\n";
    std::cout << "2. Mostrar archivo\n";
    std::cout << "3. Guardar archivo\n";
    std::cout << "4. Guardar archivo como\n";
    std::cout << "5. Lineas\n";
    std::cout << "6. Palabras\n";
    std::cout << "0. Salir\n";
}

void menu5Lineas(){
    std::cout << "1- Crear nueva linea \n";
    std::cout << "2- Insertar linea en posicion deseada \n";
    std::cout << "3- Mover linea de una posicion a otra \n";
    std::cout << "4- Eliminar linea deseada \n";
    std::cout << "0- Volver al menu anterior \n";
    std::cout << "\n";
    std::cout << "Elija una opcion \n";
    std::cout << "\n";
}

void menu6Palabras(){
    std::cout << "1- Buscar palabra \n";
    std::cout << "2- Eliminar palabra de una linea deseada \n";
    std::cout << "3- Modificar palabra de una linea deseada \n";
    std::cout << "4- Sustituir palabra de una linea deseada \n";
    std::cout << "0- Volver al menu anterior \n";
    std::cout << "\n";
    std::cout << "Elija una opcion \n";
    std::cout << "\n";
}

/*void crearLinea(Lista ** punteroLinea){
    Lista *line = new Lista;
    line = *punteroLinea;
    line -> valor = 1;
    insertarEnCola(&line, line -> valor);
    if (lineaVacia){
        std::cout << "Cuantas palabras contiene la linea? \n";
        int x = pedirEntero("");
        insertarPalabra(&line, );
    }
}*/

bool siNo(){
    std::string opcion;
    bool terminar=false;
    do {
        std::getline(std::cin, opcion);
        if (opcion == "si" || opcion == "s"){
            return true;
        }
        else if (opcion == "no" || opcion == "n"){
        return false;
        }
        else{
            std::cout << "responda con si o no \n";
        }
    } while (!terminar);
}

int pedirEntero(const std::string &pregunta)
{
    int numero = 0;
    bool termino = false;
    std::string entrada;
    std::cout << pregunta;

    do
    {
        std::getline(std::cin, entrada);
        try
        {
            numero = std::stoi(entrada);
            termino = true;
        }
        catch (const std::exception &e)
        {
            std::cerr << "ingrese un numero entero:" << std::endl;
            termino = false;
        }
        /* code */
    } while (!termino);
    return numero;
}

int main(){
    int opcion = 1;
    std::string entrada;
    Documento *doc=nullptr;
    Lista *lineaNueva=nullptr;
    do
    {
        interfazMenuPrincipal();
        opcion = pedirEntero("");
        switch (opcion)
        {
        case 0:
            std::cout << "Gracias por usar Filimbre IDE, bye bye!"<<std::endl;
            std::getline(std::cin, entrada);
            std::exit(0);
            break;

        case 1:
            // leer el documento y si no existe abre uno en blanco.
            clear();
            if (doc != nullptr){
                std::cout << "se va a borrar el archivo en RAM, quiere continuar? [si/no]: \n";
                if(siNo()){
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
            std::getline(std::cin, entrada);
            break;

        case 3:
            clear();
            break;

        case 4:
            clear();
            break;

        case 5:  
            clear();
            menu5Lineas();
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
            menu6Palabras();
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